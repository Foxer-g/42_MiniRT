/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:44:18 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 10:14:50 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	key_rotate(t_data *data, int key)//non fonctionnelle attendre que les champs calculatoire soit remplis
{
	if (key == MLX_KEY_A)
		data->ren->beta -= 0.02;
	else if (key == MLX_KEY_D)
		data->ren->beta += 0.02;
	else if (key == MLX_KEY_S)
		data->ren->alpha -= 0.02;
	else if (key == MLX_KEY_W)
		data->ren->alpha += 0.02;
	else if (key == MLX_KEY_Q)
		data->ren->gamma -= 0.02;
	else if (key == MLX_KEY_E)
		data->ren->gamma += 0.02;
	if (data->ren->alpha > (2 * M_PI) || data->ren->alpha < (-2 * M_PI))
		data->ren->alpha = 0.0;
	if (data->ren->beta > (2 * M_PI) || data->ren->beta < (-2 * M_PI))
		data->ren->beta = 0.0;
	if (data->ren->gamma > (2 * M_PI) || data->ren->gamma < (-2 * M_PI))
		data->ren->gamma = 0.0;
	printf(ORANGE"KEY_ROTATE"RESET"\n");
	renderer(data);
}

void	zoom(t_data *data, int key)//non fonctionnelle attendre que les champs calculatoire soit remplis
{
	if (key == MLX_KEY_MINUS || key == MLX_KEY_KP_MINUS)
	{
		data->ren->offset_x = (data->width / 2)
			- ((data->width / 2) - data->ren->offset_x) * MSCALE;
		data->ren->offset_y = (data->height / 2)
			- ((data->height / 2) - data->ren->offset_y) * MSCALE;
		data->ren->scale *= MSCALE;
	}
	else
	{
		data->ren->offset_x = (data->width / 2)
			- ((data->width / 2) - data->ren->offset_x) * PSCALE;
		data->ren->offset_y = (data->height / 2)
			- ((data->height / 2) - data->ren->offset_y) * PSCALE;
		data->ren->scale *= PSCALE;
	}
	printf(ORANGE"ZOOM"RESET"\n");
	renderer(data);
}

void	reset_sim(t_data *data)
{
	printf(ORANGE"RESET_SIM"RESET"\n");
	renderer(data);
}
