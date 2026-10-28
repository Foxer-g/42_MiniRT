/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 09:55:23 by toespino          #+#    #+#             */
/*   Updated: 2026/10/28 17:12:57 by ethutin-         ###   ########.fr       */
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
	(void)ray;
	(void)obj;
	return (true);
}

bool	render_cylinder(t_vector ray, int32_t index, \
t_data *scene, t_color *pixel)
{
	(void) ray;
	(void) index;
	(void) scene;
	(void) pixel;
	return (true);
}
