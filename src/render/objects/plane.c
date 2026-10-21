/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 09:55:28 by toespino          #+#    #+#             */
/*   Updated: 2026/10/21 07:53:31 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	plane_distance(t_vector ray, t_plane obj)
{
	double		denom;
	t_vector	o;

	denom = vector_dot(obj.normal, ray);
	if (denom > 0.000001)
	{
		o = vector_sub(obj.coordinate, (t_vector){.x = 0, .y = 0, .z = 0});
		return (vector_dot(o, obj.normal) / denom);
	}
	else
		return (-1.0);
}

bool	plane_intersect(t_vector ray, t_plane obj)
{
	double		denom;
	t_vector	o;

	denom = vector_dot(obj.normal, ray);
	if (denom > 0.000001)
	{
		o = vector_sub(obj.coordinate, (t_vector){.x = 0, .y = 0, .z = 0});
		return ((vector_dot(o, obj.normal) / denom) >= 0);
	}
	else
		return (false);
}

bool	render_plane(t_vector ray, int32_t i, t_data scene, t_color *pixel)
{
	*pixel = render_point(point, scene, i, scene.objs[i].normal);
	return (true);
}
