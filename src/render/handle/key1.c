/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:52:38 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 17:11:36 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	arrow_move(t_data *data, int key)
{
	if (key == K_RIGHT || key == K_6)
		update_pos(data, 0, -SPACE);
	else if (key == K_LEFT || key == K_4)
		update_pos(data, 0, SPACE);
	else if (key == K_UP || key == K_8)
		update_pos(data, 1, -SPACE);
	else if (key == K_DOWN || key == K_5)
		update_pos(data, 1, SPACE);
	else if (key == K_7)
		update_pos(data, 2, SPACE);
	else if (key == K_9)
		update_pos(data, 2, -SPACE);
	printf(ORANGE"ARROW_MOVE"RESET"\n");
	renderer(data);
}

void	z_scale(t_data *data, int key)//non fonctionnelle atendre les champs calculatoire soit complet 
{
	if (key == K_KP_DIVIDE)
	{
		data->ren->z_scale *= MINUS_SCALE;
		if (data->ren->z_scale <= Z_MIN)
			data->ren->z_scale = Z_MIN;
	}
	else if (key == K_KP_MULTIPLY)
	{
		data->ren->z_scale *= PLUS_SCALE;
		if (data->ren->z_scale >= Z_MAX)
			data->ren->z_scale = Z_MAX;
	}
	printf(ORANGE"Z_SCALE"RESET"\n");
	renderer(data);
}

static void	full_screen(t_data *data)
{
	if (data->ren->full)
		data->ren->full = false;
	else
		data->ren->full = true;
	mlx_set_window_fullscreen(data->m_st->mlx, data->m_st->win, data->ren->full);
	printf(ORANGE"FULL_SCREEN : %d"RESET"\n", data->ren->full);
}

void	central_keyup(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == K_SPACE)
		data->ren->click_space = false;
}

void	central_keypress(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	printf(ORANGE"key = %d"RESET"\n", key);
	if (key == K_ESCAPE)
		mlx_loop_end(data->m_st->mlx);
	else if (key == K_SPACE)
		data->ren->click_space = true;
	else if (key == K_W || key == K_S || key == K_A || key == K_D
		|| key == K_Q || key == K_E)
		key_rotate(data, key);
	else if (key == K_MINUS || key == K_KP_MINUS
		|| key == K_KP_PLUS)
		zoom(data, key);
	else if (key == K_F)
		full_screen(data);
	else if (key == K_KP_0 || key == K_R)
		reset_sim(data);
	else if (is_k_arrow(key))
		arrow_move(data, key);
	else if (key == K_KP_DIVIDE || key == K_KP_MULTIPLY)
		z_scale(data, key);
	else if (key == K_KP_1 || key == K_KP_2) //non obligatoire
		key_print(data, key);
}
