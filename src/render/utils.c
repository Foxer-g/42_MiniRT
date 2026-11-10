/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:52:35 by toespino          #+#    #+#             */
/*   Updated: 2026/11/10 16:30:07 by toespino         ###   ########.fr       */
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
	int64_t		i;
	int64_t		j;

	i = 0;
	while (i < scene->height)
	{
		j = -1;
		while (++j < scene->width)
			mlx_set_image_pixel(scene->mlx->mlx, scene->mlx->img, i, j,
					scene->img_c[(i + 1) * j]);
		i++;
	}
}

int64_t	get_ray_target(t_vector ray, t_data *scene)
{
	double	closest;
	double	res;
	int64_t	i;
	int64_t	index;

	closest = DBL_MAX;
	i = -1;
	while (((t_plane *)(scene->objs))[++i].type)
	{
		if (((t_plane *)(scene->objs))[i].type == 's')
			res = sphere_distance(ray, ((t_sphere *)(scene->objs))[i]);
		else if (((t_plane *)(scene->objs))[i].type == 'c')
			res = cylinder_distance(ray, ((t_cylinder *)(scene->objs))[i]);
		else if (((t_plane *)(scene->objs))[i].type == 'p')
			res = plane_distance(ray, ((t_plane *)(scene->objs))[i]);
		if (res > 0 && res < closest)
		{
			closest = res;
			index = i;
		}
	}
	return (index);
}

static bool	intersect_ray(t_vector ray, uint64_t index, t_data *scene)
{
	uint64_t	i;
	bool		res;

	i = 0;
	res = true;
	while (((t_plane *)scene->objs)[i])
	{
		if (i != index)
		{
			res = false;
			if (((t_plane *)scene->objs)[i].type == 's')
				res = sphere_intersect(ray, ((t_sphere *)scene->objs)[i]);
			else if (((t_plane *)scene->objs)[i].type == 'c')
				res = cylinder_intersect(ray, ((t_cylinder *)scene->objs)[i]);
			else if (((t_plane *)scene->objs)[i].type == 'p')
				res = plane_intersect(ray, ((t_plane *)scene->objs)[i]);
			if (res)
				return (true);
		}
		i++;
	}
	return (false);
}

t_nc	get_color(t_vector point, t_data *scene, uint64_t index, t_vector normal)
{
	double		incidence;
	t_vector	light_ray;
	mlx_color	new_color;
	t_nc		res;

	res = (t_nc){0};
	light_ray = vector_sub((t_vector) scene->lights.coordinate, point);
	incidence = vector_dot(normal, light_ray);
	if (incidence > 0.0 && !intersect_ray(light_ray, index, scene))
	{
		incidence = sqrt(vector_dot(light_ray, light_ray));
		new_color = color_incident(((t_plane **)(scene->objs))[index]->color,
				scene->lights.color, incidence,
				scene->lights.brightness);
		light_add(&res, new_color);
	}
	return (res);
}
