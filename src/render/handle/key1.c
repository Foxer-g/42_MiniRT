/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .key1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:52:38 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 10:13:48 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	arrow_move(t_data *data, int key)
{
	if (key == MLX_KEY_RIGHT)
		update_pos(data, 0, -SPACE);
	else if (key == MLX_KEY_LEFT)
		update_pos(data, 0, SPACE);
	else if (key == MLX_KEY_UP)
		update_pos(data, 1, -SPACE);
	else if (key == MLX_KEY_DOWN)
		update_pos(data, 1, SPACE);
	printf(ORANGE"RESET_SIM"RESET"\n");
	renderer(data);
}

void	z_scale(t_data *data, int key)//non fonctionnelle atendre les champs calculatoire soit complet 
{
	if (key == MLX_KEY_KP_DIVIDE)
	{
		data->ren->z_scale *= MSCALE;
		if (data->ren->z_scale <= Z_MIN)
			data->ren->z_scale = Z_MIN;
	}
	else if (key == MLX_KEY_KP_MULTIPLY)
	{
		data->ren->z_scale *= PSCALE;
		if (data->ren->z_scale >= Z_MAX)
			data->ren->z_scale = Z_MAX;
	}
	printf(ORANGE"Z_SCALE"RESET"\n");
	renderer(data);
}

// static void	full_screen(t_data *data)
// {
// 	if (data->ren->full)
// 		data->ren->full = false;
// 	else
// 		data->ren->full = true;
// 	//mlx_set_window_fullscreen(data->m_st->mlx, data->m_st->win, data->full);
// 	printf(ORANGE"FULL_SCREEN : %d"RESET"\n", data->ren->full);

// }

void central_keyup(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == MLX_KEY_SPACE)
		data->ren->click_space = false;
}

void	central_keypress(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == MLX_KEY_ESCAPE)
		mlx_loop_end(data->m_st->mlx);
	// else if (key == MLX_KEY_SPACE)
	// 	data->ren->click_space = true;
	// else if (key == MLX_KEY_W || key == MLX_KEY_S
	// 	|| key == MLX_KEY_A || key == MLX_KEY_D
	// 	|| key == MLX_KEY_Q || key == MLX_KEY_E)
	// 	key_rotate(data, key);
	// else if (key == MLX_KEY_MINUS || key == MLX_KEY_KP_MINUS
	// 	|| key == MLX_KEY_KP_PLUS)
	// 	zoom(data, key);
	// else if (key == MLX_KEY_F)
	// 	full_screen(data);
	// else if (key == MLX_KEY_0 || key == MLX_KEY_R)
	// 	reset_sim(data);
	// else if (key == MLX_KEY_RIGHT || key == MLX_KEY_LEFT
	// 	|| key == MLX_KEY_UP || key == MLX_KEY_DOWN)
	// 	arrow_move(data, key);
	// else if (key == MLX_KEY_KP_DIVIDE || key == MLX_KEY_KP_MULTIPLY)
	// 	z_scale(data, key);
}
