/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:59:48 by toespino          #+#    #+#             */
/*   Updated: 2026/11/09 16:48:40 by toespino         ###   ########.fr       */
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

t_color	render_point(t_vector point, t_data *scene, uint64_t index, t_vector normal)
{
	t_color		res;
	t_nc		no_cap;

	no_cap = get_color(point, scene, index, normal);
	res = color_cap(no_cap);
	return (res);
}

static bool	process_pixel(t_vector point, int32_t index, t_data *scene,
		t_color *pixel)
{
	if (((t_plane **)(scene->objs))[index]->type == 's')
		return (render_sphere(point, index, scene, pixel));
	else if (((t_plane **)(scene->objs))[index]->type == 'c')
		return (render_cylinder(point, index, scene, pixel));
	else if (((t_plane **)(scene->objs))[index]->type == 'p')
		return (render_plane(point, index, scene, pixel));
	return (false);
}

static bool	calculate_pixel(int32_t x, int32_t y, t_color *pixel, t_data *scene)
{
	t_vector	ray;
	t_vector	point;
	double		to_render;

	ray = generate_ray(x, y, scene);
	vector_normalize(&ray);
	to_render = get_ray_target(ray, scene);
	if (to_render == -1)
	{
		*pixel = (t_color){0};
		return (true);
	}
	point = vector_coordinate(ray, to_render);
	if (!process_pixel(point, to_render, scene, pixel))
		return (false);
	return (true);
}

bool	render(t_data *scene)
{
	t_color	*img;
	int32_t	i;
	int32_t	j;

	img = ft_calloc(scene->height * scene->width + 1, sizeof(t_color));
	if (!img)
		return (false);
	i = -1;
	while (++i < scene->height)
	{
		j = -1;
		while (++j < scene->width)
			if (!calculate_pixel(i, j, &img[(i + 1) * j], scene))
				return (ff_free(img));
	}
	create_img(img, scene->height, scene->width, scene->mlx);
	if (!scene->mlx->img)
		return (ff_free(img));
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->win, scene->mlx->img, 0, 0);
	free(img);
	mlx_destroy_image(scene->mlx->mlx, scene->mlx->img);
	return (true);
}
