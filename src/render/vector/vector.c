/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 04:55:00 by toespino          #+#    #+#             */
/*   Updated: 2026/10/13 05:54:02 by toespino         ###   ########.fr       */
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

	norm = vector_norm(vec);
	*vec.x /= norm;
	*vec.y /= norm;
	*vec.z /= norm;
}
