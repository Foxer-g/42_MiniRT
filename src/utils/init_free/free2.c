/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:47:58 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/28 15:52:54 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_plane(t_plane *plane)
{
	if (!plane)
		return ;
	if (plane->type)
		free (plane->type);
	free (plane);
}

void	free_sphere(t_sphere *sphere)
{
	if (!sphere)
		return ;
	if (sphere->type)
		free (sphere->type);
	free (sphere);
}
