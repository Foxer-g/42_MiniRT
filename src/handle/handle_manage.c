/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:59:15 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/16 09:48:10 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	select_objs(t_data *data, int64_t key)
{
	if (key == M_SCROLL_UP || key == K_KP_PLUS)
	{
		if (REN->s_index >= data->nb_objs - 1)
			REN->s_index = 0;
		else
			REN->s_index++;
	}
	else if (key == M_SCROLL_DOWN || key == K_MINUS || key == K_KP_MINUS)
	{
		if (REN->s_index <= 0)
			REN->s_index = data->nb_objs -1;
		else
			REN->s_index--;
	}
	render(data);
}

void	mlx_option(t_data *data)
{
	mlx_set_window_position(data->mlx->mlx, data->mlx->win,
		POS_X - (data->width / 2), POS_Y - (data->height / 2));
	mlx_set_fps_goal(data->mlx->mlx, FPS);
	mlx_set_font(data->mlx->mlx, TYPO);
}

void	get_hook(t_data *data)
{
	mlx_on_event(data->mlx->mlx, data->mlx->win,
		MLX_KEYDOWN, central_keypress, data);
	mlx_on_event(data->mlx->mlx, data->mlx->win,
		MLX_KEYUP, central_keyup, data);
	mlx_on_event(data->mlx->mlx, data->mlx->win,
		MLX_WINDOW_EVENT, central_window, data);
	mlx_on_event(data->mlx->mlx, data->mlx->win,
		MLX_MOUSEDOWN, central_mouse, data);
	mlx_on_event(data->mlx->mlx, data->mlx->win,
		MLX_MOUSEUP, central_mouse_up, data);
	mlx_on_event(data->mlx->mlx, data->mlx->win,
		MLX_MOUSEWHEEL, central_scroll, data);
}

void	generate_control(t_data *data)
{
	void		**objs;

	objs = (void **)data->objs;
	RENC.d_value = 0;
	RENC.i_value = 0;
	view_object(data, objs);
	view_info(data);
}

bool	generate_img(t_data *data)
{
	int64_t	i;
	int64_t	j;

	i = -1;
	if (M->img)
		mlx_destroy_image(M->mlx, M->img);
	M->img = mlx_new_image(M->mlx, data->width, data->height);
	if (!M->img)
		return (error_generic(ERR_NEW_IMG, __func__, true));
	mlx_clear_window(M->mlx, M->win, (mlx_color){.rgba = RGBA_NULL});
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
			mlx_set_image_pixel(M->mlx, M->img,
				j, i, data->img_c[i * data->width + j]);
	}
	mlx_put_image_to_window(M->mlx, M->win, M->img, 0, 0);
	if (!RENS.ctrl)
		++data->count;
	printf(D_RED"==="ORANGE"IMAGE : %ld"D_RED"==="RESET"\n", data->count);
	return (false);
}
