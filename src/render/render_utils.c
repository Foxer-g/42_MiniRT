/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:52:35 by toespino          #+#    #+#             */
/*   Updated: 2026/10/28 10:11:02 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	process_color(t_color color, double ratio)
{
	t_color	res;

	res.r = (uint8_t)(color.r * ratio);
	res.g = (uint8_t)(color.g * ratio);
	res.b = (uint8_t)(color.b * ratio);
	return (res);
}

int64_t	get_ray_target(t_vector ray, t_data *scene)
{
	void	**objs;
	double	closest;
	double	res;
	int64_t	closest_index;
	int64_t	i;

	closest = DBL_MAX;
	closest_index = -1;
	i = -1;
	objs = (void **)scene->objs;
	while (objs[++i])
	{
		res = -1.0;
		if (((t_plane *)objs[i])->type == OBJ_SPHERE)
			res = sphere_distance(ray, *(t_sphere *)objs[i]);
		else if (((t_plane *)objs[i])->type == OBJ_CYLINDER)
			res = cylinder_distance(ray, *(t_cylinder *)objs[i]);
		else if (((t_plane *)objs[i])->type == OBJ_PLANE)
			res = plane_distance(ray, *(t_plane *)objs[i]);
		if (res > 0 && res < closest)
		{
			closest = res;
			closest_index = i;
		}
	}
	return (closest_index);
}

t_vector	generate_ray(int32_t x, int32_t y, t_data *scene)
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

static bool	intersect_ray(t_vector ray, uint64_t index, t_data *scene)
{
	void		**object;
	uint64_t	i;
	bool		res;

	i = 0;
	res = true;
	object = (void **)scene->objs;
	while (object[i])
	{
		if (i == index)
			i++;
		else if (((t_plane *)object[i])->type == OBJ_SPHERE)
			res = !(sphere_intersect(ray, *(t_sphere *)object[i]));
		else if (((t_plane *)object[i])->type == OBJ_CYLINDER)
			res = !(cylinder_intersect(ray, *(t_cylinder *)object[i]));
		else if (((t_plane *)object[i])->type == OBJ_PLANE)
			res = !(plane_intersect(ray, *(t_plane *)object[i]));
		if (!res)
			return (true);
	}
	return (!res);
}

double get_ratio(t_vector point, t_data *scene, uint64_t index, 
		t_vector normal) //tmp
{
	double		tmp;
	t_vector	light_ray;

	light_ray = vector_sub(scene->lights.coordinate, point);
	tmp = ft_dmax(0.0, vector_dot(normal, light_ray));
	if (tmp != 0.0)
	{
		tmp *= scene->lights.brightness;
		if (intersect_ray(light_ray, index, scene))
			tmp = 0.0;
	}
	return (tmp);
}
