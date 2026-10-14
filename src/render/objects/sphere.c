/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 18:11:39 by toespino          #+#    #+#             */
/*   Updated: 2026/10/14 10:04:45 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	sphere_distance(t_vector ray, t_sphere obj)
{
	t_vector	pos;
    double      closest;
    double      distance;
    double      thc;

	pos = vector_sub(obj.coordinate, (t_vector) {.x = 0, .y = 0, .z = 0});
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

bool	render_sphere(t_vector ray, int32_t i, t_data scene, t_color *pixel)
{
	(void) ray;
	(void) index;
	(void) scene;
	(void) pixel;
	return (true);
}
