/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 09:55:23 by toespino          #+#    #+#             */
/*   Updated: 2026/11/20 10:39:23 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	cylinder_distance(t_vector origin, t_vector ray, t_cylinder obj)
{
	// printf(ORANGE"ENTER CYLINDER DISTANCE"RESET"\n");
	(void) origin;
	(void) ray;
	(void) obj;
	return (DBL_MAX);
}

bool	cylinder_intersect(t_vector ray, t_cylinder obj)
{
	(void)ray;
	(void)obj;
	return (true);
}

bool	render_cylinder(t_vector ray, int32_t i, t_data *scene, COLOR *pixel)
{
	(void) ray;
	(void) i;
	(void) scene;
	(void) pixel;
	return (true);
}
