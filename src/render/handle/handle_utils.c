/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:59:15 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 10:24:05 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	update_pos(t_data *data, uint8_t type, int space)//plus fonctionnelle a regler
{
	void	**object;
	int		i;

	object = (void **)data->objs;
	i = -1;
	if (type == 0)
		while (object[i])
			((t_plane *)data->objs)[i].coordinate.x += space;
	else if (type == 1)
		while (object[i])
			((t_plane *)data->objs)[i].coordinate.y += space;
	else if (type == 2)
		while (object[i])
			((t_plane *)data->objs)[i].coordinate.z += space;
}

void	mlx_option(t_data *s)
{
	//mlx_set_window_position(s->m_st->mlx, s->m_st->win, POS_X, POS_Y);
	mlx_set_fps_goal(s->m_st->mlx, FPS);
}

void	get_hook(t_data *data)
{
	mlx_on_event(data->m_st->mlx, data->m_st->win,
		MLX_KEYDOWN, central_keypress, data);
	// mlx_on_event(data->m_st->mlx, data->m_st->win,
	// 	MLX_KEYUP, central_keyup, data);
	mlx_on_event(data->m_st->mlx, data->m_st->win,
		MLX_WINDOW_EVENT, central_window, data);
	// mlx_on_event(data->m_st->mlx, data->m_st->win,
	// 	MLX_MOUSEDOWN, central_mouse, data);
	// mlx_on_event(data->m_st->mlx, data->m_st->win,
	// 	MLX_MOUSEUP, central_mouse_up, data);
	// mlx_on_event(data->m_st->mlx, data->m_st->win,
	// MLX_MOUSEWHEEL, central_mouse, data);
}

bool	generate_img(t_data *data)
{
	t_mlx	*m;

	m = data->m_st;

	if (data->m_st->img)
		mlx_destroy_image(m->mlx, m->img);
	m->img = mlx_new_image(m->mlx, data->width, data->height);
	if (!m->img)
		return (error_generic(ERR_NEW_IMG, __func__, true));
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	printf(ORANGE"NEW IMAGE"RESET"\n");
	return (false);
}
