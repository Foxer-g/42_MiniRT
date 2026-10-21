/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:59:48 by toespino          #+#    #+#             */
/*   Updated: 2026/10/21 08:09:01 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	render_point(t_vector point, t_data scene, uint64_t index,
		t_vector normal)
{
	t_color		res;
	t_vector	normal;

	ratio = ft_dmin(get_ratio(point, normal, scene, index), 1.0);
	res = process_color(scene.objs[index].color, ratio);
	return (res);
}

static bool	process_pixel(t_vector point, int32_t index, t_data scene,
		t_color *pixel)
{
	if (((t_plane) scene.objs[index].type == s))
		return (render_sphere(point, index, scene, pixel));
	else if (((t_plane) scene.objs[index].type == c))
		return (render_cylinder(point, index, scene, pixel));
	else if (((t_plane) scene.objs[index].type == p))
		return (render_plane(point, index, scene, pixel));
	else
		return (false);
}

static bool	calculate_pixel(int32_t x, int32_t y, t_color *pixel, t_data scene)
{
	t_vector	ray;
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

bool	render(t_data scene, t_mlx mlx)
{
	t_color	*img;

	img = ft_calloc(scene.height * scene.width + 1, sizeof(t_color));
	if (!img)
		return (false);
	i = -1;
	while (++i < scene.height)
	{
		j = -1;
		while (++j < scene.width)
			if (!calculate_pixel(i, j, &img[(i + 1) * j], scene))
				return (ff_free(img));
	}
	mlx.img = generate_img(img, scene.height, scene.width);
	if (!mlx.img)
		return (ff_free(img));
	if (scene.to_image)
		mlx_save_image_to_file(mlx.mlx, mlx.img, scene.to_img);
	else
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	free(img);
	mlx_dextroy_image(mlx.mlx, mlx.img);
	return (true);
}
