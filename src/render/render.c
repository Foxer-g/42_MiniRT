/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:59:48 by toespino          #+#    #+#             */
/*   Updated: 2026/11/20 11:25:06 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// static t_vector	generate_ray(int32_t x, int32_t y, t_data *scene)//the curent version in render
// {
// 	const double	aspect_ratio = ((double)scene->width
// / (double)scene->height);
// 	const double	fov_tan = tan((scene->camera.fov * (M_PI / 180)) / 2);
// 	const double	x_on_screen = (((double)x + 0.5) / scene->width);
// 	const double	y_on_screen = (((double)y + 0.5) / scene->height);
// 	t_vector		ray;

// 	ray.x = (2 * x_on_screen - 1) * aspect_ratio * fov_tan;
// 	ray.y = (1 - 2 * y_on_screen) * fov_tan;
// 	ray.z = 1;
// 	return (ray);
// }

static t_vector	generate_ray(int32_t x, int32_t y, t_data *scene)
{
	const double	aspect_ratio = (double)scene->width / (double)scene->height;
	const double	fov_tan = tan((scene->camera.fov * (M_PI / 180)) / 2);
	const double	x_screen = (((double)x - (double)scene->width / 2.0)
			- scene->ren->offset_x) / scene->ren->scale ;
	const double	y_screen = (((double)y - (double)scene->height / 2.0)
			- scene->ren->offset_y) / scene->ren->scale ;
	t_vector		ray;

	ray.x = (2.0 * x_screen / scene->width) * aspect_ratio * fov_tan;
	ray.y = (-2.0 * y_screen / scene->height) * fov_tan;
	ray.z = 1.0;
	return (ray);
}

COLOR	render_point(VEC point, t_data *scene, uint64_t index, VEC normal)
{
	mlx_color	res;
	t_nc		no_cap;

	no_cap = get_color(point, scene, index, normal);
	res = color_cap(no_cap);
	return (res);
}

static bool	process_pixel(t_vector point, int32_t index, t_data *scene,
		mlx_color *pixel)
{
	if (((t_plane **)(scene->objs))[index]->type == OBJ_SPHERE)
		return (render_sphere(point, index, scene, pixel));
	else if (((t_plane **)(scene->objs))[index]->type == OBJ_CYLINDER)
		return (render_cylinder(point, index, scene, pixel));
	else if (((t_plane **)(scene->objs))[index]->type == OBJ_PLANE)
		return (render_plane(point, index, scene, pixel));
	return (false);
}

static bool	calculate_pixel(int32_t x, int32_t y, int64_t index, t_data *scene)
{
	t_vector	ray;
	t_vector	point;
	int64_t		to_render;
	double		distance;

	ray = generate_ray(x, y, scene);
	vector_normalize(&ray);
	to_render = get_ray_target(ray, scene, &distance);
	scene->img_c[index] = (mlx_color){.rgba = 0xFFFFFF};
	if (to_render == -1)
	{
		scene->img_c[index] = (mlx_color){0};
		return (true);
	}
	else
	{
		point = vector_coordinate(ray, distance);
		if (!process_pixel(point, to_render, scene, &(scene->img_c[index])))
			return (false);
	}
	return (true);
}

// bool	render(t_data *scene) // current version
// {
// 	int32_t	i;
// 	int32_t	j;

// 	i = -1;
// 	while (++i < scene->height)
// 	{
// 		j = -1;
// 		while (++j < scene->width)
// 		{
// 			if (!calculate_pixel(j, i, i * scene->width + j, scene))
// 				return (true);
// 		}
// 	}
// 	scene->mlx->img = mlx_new_image(scene->mlx->mlx,
// 			scene->width, scene->height);
// 	if (!scene->mlx->img)
// 		return (true);
// 	create_img(scene);
// 	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->win,
// 		scene->mlx->img, 0, 0);
// 	return (false);
// }

bool	render(t_data *data) // teste en utilisant celle-ci
{
	int32_t	i;
	int32_t	j;

	i = -1;
	if (!RENS.ctrl)// evite de recalculer pour chaque commande faite dans control
	{
		while (++i < data->height)
		{
			j = -1;
			while (++j < data->width)
				if (!calculate_pixel(j, i, i * data->width + j, data))
					return (error_generic(ERR_UNKNOW_OBJECT, __func__, true));
			
				// if (!calculate_pixel(j, i, i * data->width + j, data))//current version in render
				// 	return (true);
				//data->img_c[i * data->width + j].rgba = RGBA_MAG;//for testing whiout calculating
		}
	}
	if (generate_img(data))// in src/handle/handle_manage
		return (true);
	if (RENS.ctrl)
		generate_control(data);// in src/handle/handle_manage
	return (false);
	/*
	La gestion sim et etet penser autour de generate_img et generate_control, 
	il serait je pense preferable de les utilsait au lieu de create_img.
	Mes generate remplisant deja le role que create_img plus la gestion de control
	*/
}
