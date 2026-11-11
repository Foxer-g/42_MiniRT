/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:59:48 by toespino          #+#    #+#             */
/*   Updated: 2026/11/11 18:57:56 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vector	generate_ray(int32_t x, int32_t y, t_data *scene)
{
	const double	aspect_ratio = (scene->width / scene->height);
	const double	fov_tan = tan((scene->camera.fov * (M_PI / 180)) / 2);
	const double	x_on_screen = (((double)x + 0.5) / scene->width);
	const double	y_on_screen = (((double)y + 0.5) / scene->height);
	t_vector		ray;

	ray.x = (2 * x_on_screen - 1) * aspect_ratio * fov_tan;
	ray.y = (1 - 2 * y_on_screen) * fov_tan;
	ray.z = 1;
	return (ray);
}

mlx_color	render_point(t_vector point, t_data *scene, uint64_t index, t_vector normal)
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

	ray = generate_ray(x, y, scene);
	vector_normalize(&ray);
	to_render = get_ray_target(ray, scene);
	if (to_render == -1)
	{
		scene->img_c[index] = (mlx_color){0};
		return (true);
	}
	else
	{
		point = vector_coordinate(ray, to_render);
		if (!process_pixel(point, to_render, scene, &(scene->img_c[index])))
			return (false);
	}
	return (true);
}

bool	render(t_data *scene)
{
	int32_t	i;
	int32_t	j;

	i = -1;
	while (++i < scene->height)
	{
		j = -1;
		while (++j < scene->width)
			if (!calculate_pixel(i, j, (i + 1) * j, scene))
				return (true);
	}
	scene->mlx->img = mlx_new_image(scene->mlx->mlx, scene->height,
		scene->width);
	create_img(scene);
	if (!scene->mlx->img)
		return (true);
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->win, scene->mlx->img,
		0, 0);
	return (false);
}
