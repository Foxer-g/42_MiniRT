/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:47:58 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 17:12:57 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_plane(t_plane *plane)
{
	if (!plane)
		return ;
	free (plane);
}

void	free_sphere(t_sphere *sphere)
{
	if (sphere)
		free (sphere);
}

void	free_camera(t_cam *camera)
{
	if (!camera)
		return ;
	free(camera);
}

void	free_light(t_light *light)
{
	if (!light)
		return ;
	free (light);
}

void	free_cylinder(t_cylinder *cylinder)
{
	if (cylinder)
		free (cylinder);
}
