/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 18:11:39 by toespino          #+#    #+#             */
/*   Updated: 2026/11/17 06:25:55 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	sphere_distance(t_vector origin, t_vector ray, t_sphere obj)
{
	t_vector	pos;
	double		param[3];
	double		delta;
	double		t;

	pos = vector_sub(origin, obj.coordinate);
	param[0] = vector_dot(ray, ray);
	if (param[0] == 0.0)
		return (-1.0);
	param[1] = 2.0 * vector_dot(pos, ray);
	param[2] = vector_dot(pos, pos) - obj.radius * obj.radius;
	delta = param[1] * param[1] - 4.0 * param[0] * param[2];
	if (delta < 0.0)
		return (-1.0);
	t = (-param[1] - sqrt(delta)) / (2.0 * param[0]);
	if (t >= 0.0)
		return (t);
	t = (-param[1] + sqrt(delta)) / (2.0 * param[0]);
	if (t >= 0.0)
		return (t);
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
	distance = vector_dot(pos, pos) - pow(closest, 2);
	if (distance > pow(obj.radius, 2))
		return (false);
	discriminant = 4.0 * (pow(obj.radius, 2) - distance);
	if (discriminant >= 0)
		return (true);
	return (false);
}

bool	render_sphere(t_vector point, int32_t i, t_data *scene, COLOR *pixel)
{
	t_vector	normal;

	normal = vector_sub(point,
			((t_sphere *)scene->objs[i])->coordinate);
	*pixel = render_point(point, scene, i, normal);
	return (true);
}
