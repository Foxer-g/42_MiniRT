/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:52:35 by toespino          #+#    #+#             */
/*   Updated: 2026/11/07 13:09:56 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	ff_free(void *input)
{
	free(input);
	return (false);
}

void	generate_img(t_color *img, int32_t height, int32_t width, t_mlx *mlx)
{
	int64_t		i;
	int64_t		j;

	i = 0;
	while (i < height)
	{
		j = -1;
		while (++j < width)
			mlx_set_image_pixel(mlx->mlx, mlx->img, i, j,
				to_mlx(img[(i + 1) * j]));
		i++;
	}
}

double	get_ray_target(t_vector ray, t_data scene)
{
	double	closest;
	double	res;
	int64_t	i;

	closest = DBL_MAX;
	i = -1;
	while (((t_plane *)(scene.objs))[++i].type)
	{
		if (((t_plane *)(scene.objs))[i].type == 's')
			res = sphere_distance(ray, ((t_sphere *)(scene.objs))[i]);
		else if (((t_plane *)(scene.objs))[i].type == 'c')
			res = cylinder_distance(ray, ((t_cylinder *)(scene.objs))[i]);
		else if (((t_plane *)(scene.objs))[i].type == 'p')
			res = plane_distance(ray, ((t_plane *)(scene.objs))[i]);
		if (res > 0 && res < closest)
			closest = res;
	}
	return (closest);
}

static bool	intersect_ray(t_vector ray, uint64_t index, t_data scene)
{
	uint64_t	i;
	bool		res;

	i = 0;
	res = true;
	while (scene.objs)
	{
		if (i == index)
			i++;
		else if (((t_plane *)(scene.objs))[i].type == 's')
			res = !(sphere_intersect(ray, ((t_sphere *)(scene.objs))[i]));
		else if (((t_plane *)(scene.objs))[i].type == 'c')
			res = !(cylinder_intersect(ray, ((t_cylinder *)(scene.objs))[i]));
		else if (((t_plane *)(scene.objs))[i].type == 'p')
			res = !(plane_intersect(ray, ((t_plane *)(scene.objs))[i]));
		if (!res)
			return (true);
	}
	return (!res);
}

t_nc	get_color(t_vector point, t_data scene, uint64_t index, t_vector normal)
{
	uint64_t	i;
	double		incidence;
	t_vector	light_ray;
	t_color		new_color;
	t_nc		res;

	i = 0;
	res = (t_nc){0};
	while (scene.lights[i].brightness >= 0.0)
	{
		light_ray = vector_sub((t_vector) scene.lights[i].coordinate, point);
		incidence = vector_dot(normal, light_ray);
		if (incidence > 0.0 && !intersect_ray(light_ray, index, scene))
		{
			incidence /= sqrt(vector_dot(light_ray, light_ray));
			new_color = color_incident(((t_plane **)(scene.objs))[index]->color,
					scene.lights[i].color, incidence,
					scene.lights[i].brightness);
			light_add(&res, new_color);
		}
		i++;
	}
	return (res);
}
