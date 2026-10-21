/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:52:35 by toespino          #+#    #+#             */
/*   Updated: 2026/10/21 08:06:51 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	process_color(t_color color, double ratio)
{
	t_color	res;

	res.r = (uint8_t) (color.r * ratio);
	res.g = (uint8_t) (color.g * ratio);
	res.b = (uint8_t) (color.b * ratio);
	return (res);
}

double	get_ray_target(t_vector ray, t_data scene)
{
	double	closest;
	int64_t	i;

	closest = DBL_MAX;
	closest_index = -1;
	i = -1;
	while (scene.(t_plane)obj[++i].type)
	{
		if (scene.(t_plane)obj[i].type == 's')
			res = sphere_distance(ray, scene.(t_sphere)obj[i]);
		else if (scene.(t_plane)obj[i].type == 'c')
			res = cylinder_distance(ray, scene.(t_cylinder)obj[i]);
		else if (scene.(t_plane)obj[i].type == 'p')
			res = plane_distance(ray, scene.(t_plane)obj[i]);
		if (res > 0 && res < closest)
			closest = res;
	}
	return (closest);
}

t_vector	generate_ray(int32_t x, int32_t y, t_data scene)
{
	const double	aspect_ratio = (scene.width / scene.height);
	const double	fov_tan = tan((scene.fov * (M_PI / 180)) / 2);
	const double	x_on_screen = (((double)x + 0.5) / scene.width);
	const double	y_on_screen = (((double)y + 0.5) / scene.height);
	t_vector		ray;

	ray.x = (2 * x_on_screen - 1) * aspect_ratio * fov_tan;
	ray.y = (1 - 2 * y_on_screen) * fov_tan;
	ray.z = 1;
	return (ray);
}

static bool	intersect_ray(t_vector ray, uint64_t index, t_data scene)
{
	uint64_t	i;
	bool		res;

	i = 0;
	res = true;
	while (scene.obj)
	{
		if (i == index)
			i++;
		else if (scene.(t_plane)obj[i].type == 's')
			res = !(sphere_intersect(ray, scene.(t_sphere)obj[i]));
		else if (scene.(t_plane)obj[i].type == 'c')
			res = !(cylinder_intersect(ray, scene.(t_cylinder)obj[i]));
		else if (scene.(t_plane)obj[i].type == 'p')
			res = !(plane_intersect(ray, scene.(t_plane)obj[i]));
		if (!res)
			return (true);
	}
	return (!res);
}

double	get_ratio(t_vector point, t_data scene, uint64_t index, t_vector normal)
{
	uint64_t	i;
	double		tmp;
	double		res;

	i = 0;
	while (scene.lights[i])
	{
		light_ray = vector_sub(scene.lights[i].coordinate, normal);
		tmp = ft_dmax(0.0, vector_dot(normal, light_ray));
		if (tmp != 0.0)
		{
			tmp *= scene.lights[i].brightness;
			if (intersect_ray(light_ray, index, scene))
				tmp = 0.0;
		}
		res += tmp;
		i++;
	}
	return (res);
}
