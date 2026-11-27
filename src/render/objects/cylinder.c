/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 09:55:23 by toespino          #+#    #+#             */
/*   Updated: 2026/11/17 06:26:32 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vector cylinder_coeff(t_vector origin, t_vector ray,
        t_cylinder obj)
{
    t_vector axis;
    t_vector oc;
    t_vector rd_perp;
    t_vector oc_perp;

    axis = obj.normal;
    oc = vector_sub(origin, obj.coordinate);
    rd_perp = vector_sub(ray, vector_coordinate(axis,
            vector_dot(ray, axis)));
    oc_perp = vector_sub(oc, vector_coordinate(axis,
            vector_dot(oc, axis)));
    return ((t_vector){vector_dot(rd_perp, rd_perp),
        vector_dot(rd_perp, oc_perp),
        vector_dot(oc_perp, oc_perp)
        - pow(obj.diameter / 2.0, 2)});
}

static bool cylinder_height(t_vector origin, t_vector ray,
        t_cylinder obj, double t)
{
    t_vector oc;
    t_vector hit;
    double projection;

    oc = vector_sub(origin, obj.coordinate);
    hit = vector_add(oc, vector_coordinate(ray, t));
    projection = vector_dot(hit, obj.normal);
    return (fabs(projection) <= obj.height / 2.0);
}

double cylinder_distance(t_vector origin, t_vector ray, t_cylinder obj)
{
    t_vector coeff;
    double delta;
    double t;
    double root;

    coeff = cylinder_coeff(origin, ray, obj);
    delta = coeff.y * coeff.y - coeff.x * coeff.z;
    if (delta < 0.0 || coeff.x == 0.0)
        return (-1.0);
    root = sqrt(delta);
    t = (-coeff.y - root) / coeff.x;
    if (t >= 0.0 && cylinder_height(origin, ray, obj, t))
        return (t);
    t = (-coeff.y + root) / coeff.x;
    if (t >= 0.0 && cylinder_height(origin, ray, obj, t))
        return (t);
    return (-1.0);
}

bool	render_cylinder(t_vector point, int32_t i, t_data *scene,
		COLOR *pixel)
{
	t_vector	normal;
	t_vector	offset;
	double		projection;

	offset = vector_sub(point,
			((t_cylinder *)((void **)scene->objs)[i])->coordinate);
	projection = vector_dot(offset,
			((t_cylinder *)((void **)scene->objs)[i])->normal);
	normal = vector_sub(offset, vector_coordinate(
			((t_cylinder *)((void **)scene->objs)[i])->normal,
			projection));
	*pixel = render_point(point, scene, i, normal);
	return (true);
}
