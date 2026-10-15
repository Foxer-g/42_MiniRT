/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:40:48 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 19:03:27 by ethutin-         ###   ########.fr       */
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
		o = vector_sub((t_vector){.x = obj.coordinate.x, .y = obj.coordinate.y, \
.z = obj.coordinate.z}, (t_vector){.x = 0, .y = 0, .z = 0});
		return (vector_dot(o, obj.normal) / denom);
	}
	else
		return (-1.0);
}

bool	render_plane(t_vector ray, int32_t index, \
t_data *scene, t_color *pixel)
{
	(void)ray;
	(void)index;
	(void)scene;
	(void)pixel;
	return (true);
}
