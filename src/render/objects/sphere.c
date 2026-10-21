/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 18:11:39 by toespino          #+#    #+#             */
/*   Updated: 2026/10/21 07:45:29 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	sphere_distance(t_vector ray, t_sphere obj)
{
	t_vector	pos;
	double		closest;
	double		distance;
	double		thc;

	pos = vector_sub(obj.coordinate, (t_vector){.x = 0, .y = 0, .z = 0});
	closest = vector_dot(pos, ray);
	distance = vec_dot(pos, pos) - pow(closest, 2);
	if (distance > pow(obj.radius, 2))
		return (-1.0);
	thc = sqrt(pow(obj.radius, 2) - distance);
	if (closest - thc >= 0)
		return (closest - thc);
	if (closest + thc >= 0)
		return (closest + thc);
	return (-1.0);
}

bool	sphere_intersect(t_vector ray, t_sphere obj)
{
	t_vector	pos;
	double		closest;
	double		distance;
	double		discriminant;

	pos = vector_sub(obj.coordinate, (t_vector){.x = 0, .y = 0, .z = 0});
	closest = vector_dot(pos, ray);
	distance = vec_dot(pos, pos) - pow(closest, 2);
	if (distance > pow(obj.radius, 2))
		return (false);
	discriminant = 4.0 * (pow(obj.radius, 2) - distance);
	if (discriminant >= 0)
		return (true);
	return (false);
}

bool	render_sphere(t_vector point, int32_t i, t_data scene, t_color *pixel)
{
	t_vector	normal;

	normal = vector_sub(point, scene.objs[i].coordinate);
	*pixel = render_point(point, scene, i, normal);
	return (true);
}
