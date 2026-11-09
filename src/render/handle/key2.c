/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:44:18 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 16:41:52 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	key_rotate(t_data *data, int key)//non fonctionnelle attendre que les champs calculatoire soit remplis
{
	if (key == K_A)
		data->ren->beta -= 0.02;
	else if (key == K_D)
		data->ren->beta += 0.02;
	else if (key == K_S)
		data->ren->alpha -= 0.02;
	else if (key == K_W)
		data->ren->alpha += 0.02;
	else if (key == K_Q)
		data->ren->gamma -= 0.02;
	else if (key == K_E)
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
	if (key == K_MINUS || key == K_KP_MINUS)
	{
		data->ren->offset_x = (data->width / 2)
			- ((data->width / 2) - data->ren->offset_x) * MINUS_SCALE;
		data->ren->offset_y = (data->height / 2)
			- ((data->height / 2) - data->ren->offset_y) * MINUS_SCALE;
		data->ren->scale *= MINUS_SCALE;
	}
	else
	{
		data->ren->offset_x = (data->width / 2)
			- ((data->width / 2) - data->ren->offset_x) * PLUS_SCALE;
		data->ren->offset_y = (data->height / 2)
			- ((data->height / 2) - data->ren->offset_y) * PLUS_SCALE;
		data->ren->scale *= PLUS_SCALE;
	}
	printf(ORANGE"ZOOM"RESET"\n");
	renderer(data);
}

void	reset_sim(t_data *data)
{
	data->ren->offset_x = 0;
	data->ren->offset_y = 0;
	data->ren->offset_z = 0;
	data->ren->alpha = DEFAULT_ALPHA;
	data->ren->beta = DEFAULT_BETA;
	data->ren->gamma = 0;
	data->ren->scale = 1;
	data->ren->z_scale = 1;
	printf(ORANGE"RESET_SIM"RESET"\n");
	renderer(data);
}

void	key_print(t_data *data, int key)
{
	if (key == K_KP_1)
		print_param(data);
	if (key == K_KP_2)
		print_struct(data);
	printf(ORANGE"KEY_PRINT"RESET"\n");
}
