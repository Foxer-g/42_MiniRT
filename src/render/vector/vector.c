/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 04:55:00 by toespino          #+#    #+#             */
/*   Updated: 2026/10/21 03:01:24 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	vector_norm(t_vector vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}

void	vector_normalize(t_vector *vec)
{
	double		norm;

	norm = vector_norm(*vec);
	vec->x /= norm;
	vec->y /= norm;
	vec->z /= norm;
}

void	vector_inv(t_vector *vec)
{
	vec->x = -vec->x;
	vec->y = -vec->y;
	vec->z = -vec->z;
}

t_vector	vector_coordinate(t_vector vec, double t)
{
	t_vector	res;

	res.x = vec.x * t;
	res.y = vec.y * t;
	res.z = vec.z * t;
	return (res);
}
