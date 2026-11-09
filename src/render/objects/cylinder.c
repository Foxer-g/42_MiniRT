/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 09:55:23 by toespino          #+#    #+#             */
/*   Updated: 2026/11/09 12:56:08 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	cylinder_distance(t_vector ray, t_cylinder obj)
{
	(void) ray;
	(void) obj;
	return (DBL_MAX);
}

bool	cylinder_intersect(t_vector ray, t_cylinder obj)
{
	(void) ray;
	(void) obj;
	return (true);
}

bool	render_cylinder(t_vector ray, int32_t i, t_data scene, t_color *pixel)
{
	(void) ray;
	(void) scene;
	(void) pixel;
	(void) i;
	return (true);
}
