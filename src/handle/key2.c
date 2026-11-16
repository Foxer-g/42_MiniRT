/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:44:18 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/16 09:46:38 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	select_data(t_data *data, int key)
{
	void	**objs;

	objs = (void **)data->objs;
	if (((t_plane *)objs[data->ren->s_index])->type == OBJ_SPHERE
		&& key == K_KP_1 && !data->ren->stor.height
		&& !data->ren->stor.diameter)
		data->ren->stor.radius = !data->ren->stor.radius;
	else if (((t_plane *)objs[data->ren->s_index])->type == OBJ_CYLINDER)
	{
		if (key == K_KP_1 && !data->ren->stor.radius
			&& !data->ren->stor.height)
			data->ren->stor.diameter = !data->ren->stor.diameter;
		else if (key == K_KP_2 && !data->ren->stor.radius
			&& !data->ren->stor.diameter)
			data->ren->stor.height = !data->ren->stor.height;
	}
}

void	arrow_move(t_data *data, int key)
{
	if (RENS.ctrl)
		return ;
	else if (key == K_RIGHT || key == K_6)
		REN->offset_x += SPACE;
	else if (key == K_LEFT || key == K_4)
		REN->offset_x -= SPACE;
	else if (key == K_UP || key == K_8)
		REN->offset_y += SPACE;
	else if (key == K_DOWN || key == K_5)
		REN->offset_y -= SPACE;
	render(data);
}

void	z_scale(t_data *data, int key)
{
	double	factor;

	factor = FACTOR;
	if (key == K_KP_DIVIDE)
		factor = -factor;
	REN->z_scale *= exp(factor);
	if (REN->z_scale <= Z_MIN)
		REN->z_scale = Z_MIN;
	render(data);
}

void	rotate(t_data *data, int key)
{
	if (key == K_A)
		REN->beta -= 0.02;
	else if (key == K_D)
		REN->beta += 0.02;
	else if (key == K_S)
		REN->alpha -= 0.02;
	else if (key == K_W)
		REN->alpha += 0.02;
	else if (key == K_Q)
		REN->gamma -= 0.02;
	else if (key == K_E)
		REN->gamma += 0.02;
	if (REN->alpha > (2 * M_PI) || REN->alpha < (-2 * M_PI))
		REN->alpha = 0.0;
	if (REN->beta > (2 * M_PI) || REN->beta < (-2 * M_PI))
		REN->beta = 0.0;
	if (REN->gamma > (2 * M_PI) || REN->gamma < (-2 * M_PI))
		REN->gamma = 0.0;
	render(data);
}

void	zoom(t_data *data, int key)
{
	double	factor;

	factor = FACTOR;
	if (key == K_MINUS || key == K_KP_MINUS)
		factor = -factor;
	REN->offset_x = (data->width / 2)
		- ((data->width / 2) - REN->offset_x) * exp(factor);
	REN->offset_y = (data->height / 2)
		- ((data->height / 2) - REN->offset_y) * exp(factor);
	REN->scale *= exp(factor);
	render(data);
}
