/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minoris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:37:24 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 18:57:23 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	init_vector(void **objs, uintmax_t *i)
{
	t_vector	vector;

	vector.x = *(double *)objs[*i];
	vector.y = *(double *)objs[*i + 1];
	vector.z = *(double *)objs[*i + 2];
	*i += 3;
	return (vector);
}

t_coord	init_coordinate(void **objs, uintmax_t *i)
{
	t_coord	coordinate;

	coordinate.x = *(double *)objs[*i];
	coordinate.y = *(double *)objs[*i + 1];
	coordinate.z = *(double *)objs[*i + 2];
	*i += 3;
	return (coordinate);
}

t_color	init_color(void **objs, uintmax_t *i)
{
	t_color	color;

	color.r = *(uint8_t *)objs[*i];
	color.g = *(uint8_t *)objs[*i + 1];
	color.b = *(uint8_t *)objs[*i + 2];
	*i += 3;
	return (color);
}
