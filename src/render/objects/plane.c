/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:40:48 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 09:53:26 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	plane_distance(t_vector ray, t_plane obj)
{
	double		denom;
	t_vector	sub;

	denom = vector_dot(obj.normal, ray);
	if (denom > 0.000001)
	{
		sub = vector_sub(obj.coordinate, (t_vector){.x = 0, .y = 0, .z = 0});
		return (vector_dot(sub, obj.normal) / denom);
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

bool	render_plane(t_vector point, int32_t i, t_data *scene, t_color *pixel)
{
	*pixel = render_point(point, scene, i, ((t_plane *)scene->objs)[i].normal);
	return (true);
}
