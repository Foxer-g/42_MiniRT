/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 09:55:28 by toespino          #+#    #+#             */
/*   Updated: 2026/11/17 06:22:41 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	plane_distance(t_vector origin, t_vector ray, t_plane obj)
{
	double	denom;
	double	t;

	denom = vector_dot(obj.normal, ray);
	if (fabs(denom) < 0.000001)
		return (-1.0);
	t = vector_dot(vector_sub(obj.coordinate, origin),
			obj.normal) / denom;
	if (t < 0.0)
		return (-1.0);
	return (t);
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

bool	render_plane(t_vector p, int32_t i, t_data *scene, COLOR *pixel)
{
	*pixel = render_point(p, scene, i, ((t_plane *)(scene->objs))[i].normal);
	return (true);
}
