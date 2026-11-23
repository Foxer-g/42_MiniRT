/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:52:35 by toespino          #+#    #+#             */
/*   Updated: 2026/11/17 06:50:33 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	ff_free(void *input)
{
	free(input);
	return (false);
}

void	create_img(t_data *scene)
{
	int64_t	i;
	int64_t	j;

	i = 0;
	while (i < scene->height)
	{
		j = 0;
		while (j < scene->width)
		{
			mlx_set_image_pixel(scene->mlx->mlx, scene->mlx->img,
				j, i, scene->img_c[i * scene->width + j]);
			j++;
		}
		i++;
	}
}

int64_t	get_ray_target(t_vector ray, t_data *scene, double *distance)
{
	double	closest;
	double	res;
	int64_t	i;
	int64_t	index;

	closest = DBL_MAX;
	i = -1;
	index = -1;
	while (scene->objs[++i])
	{
		res = -1.0;
		if (((t_plane *)scene->objs[i])->type == OBJ_SPHERE)
			res = sphere_distance((t_vector){0}, ray, *(t_sphere *)scene->objs[i]);
		else if (((t_plane *)scene->objs[i])->type == OBJ_CYLINDER)
			res = cylinder_distance((t_vector){0}, ray, *(t_cylinder *)scene->objs[i]);
		else if (((t_plane *)scene->objs[i])->type == OBJ_PLANE)
			res = plane_distance((t_vector){0}, ray, *(t_plane *)scene->objs[i]);
		if (res > 0.0 && res < closest)
		{
			closest = res;
			index = i;
		}
	}
	*distance = closest;
	return (index);
}

static bool	intersect_ray(t_vector origin, t_vector ray, uint64_t index, t_data *scene)
{
	uint64_t	i;
	double		t;

	i = 0;
	while (scene->objs[i])
	{
		t = -1.0;
		if (i != index)
		{
			if (((t_plane *)scene->objs[i])->type == OBJ_SPHERE)
				t = sphere_distance(origin, ray, *(t_sphere *)scene->objs[i]);
			else if (((t_plane *)scene->objs[i])->type == OBJ_CYLINDER)
				t = cylinder_distance(origin, ray, *(t_cylinder *)scene->objs[i]);
			else if (((t_plane *)scene->objs[i])->type == OBJ_PLANE)
				t = plane_distance(origin, ray, *(t_plane *)scene->objs[i]);
		}
		if (t > 0.000001 && t < 1.0)
			return (true);
		i++;
	}
	return (false);
}

t_nc	get_color(t_vector point, t_data *scene, uint64_t index, t_vector normal)
{
	double		incidence;
	double		denom;
	t_vector	light_ray;
	mlx_color	new_color;
	t_nc		res;

	res = (t_nc){0};
	light_ray = vector_sub(scene->lights.coordinate, point);
	incidence = vector_dot(normal, light_ray);
	if (incidence <= 0.0 || intersect_ray(point, light_ray, index, scene))
		return (res);
	denom = sqrt(vector_dot(normal, normal)
			* vector_dot(light_ray, light_ray));
	if (denom == 0.0)
		return (res);
	incidence /= denom;
	new_color = color_incident(((t_plane *)scene->objs[index])->color,
			scene->lights.color, incidence, scene->lights.brightness);
	light_add(&res, new_color);
	return (res);
}
