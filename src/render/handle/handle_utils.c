/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:59:15 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/09 17:06:18 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// void	update_pos(t_data *data, uint8_t type, int space)
// {
// 	void	**objs;
// 	int64_t	index;

// 	objs = (void **)data->objs;
// 	index = -1;
// 	if (type == 0)
// 		while (objs[++index])
// 			OBJECT->coordinate.x += space;
// 	else if (type == 1)
// 		while (objs[++index])
// 			OBJECT->coordinate.y += space;
// 	else if (type == 2)
// 		while (objs[++index])
// 			OBJECT->coordinate.z += space;
// }

void	update_pos(t_data *data, uint8_t type, int space)
{
	if (type == 0)
		data->ren->offset_x += space;
	else if (type == 1)
		data->ren->offset_y += space;
	else if (type == 2)
		data->ren->offset_z += space;
}

void	mlx_option(t_data *s)
{
	//mettre center_x;y
	mlx_set_window_position(s->mlx->mlx, s->mlx->win, 980, 540);
	mlx_set_fps_goal(s->mlx->mlx, FPS);
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
		MLX_MOUSEWHEEL, central_mouse, data);
}

bool	generate_img(t_data *data)
{
	t_mlx	*m;

	m = data->mlx;
	if (data->mlx->img)
		mlx_destroy_image(m->mlx, m->img);
	m->img = mlx_new_image(m->mlx, data->width, data->height);
	if (!m->img)
		return (error_generic(ERR_NEW_IMG, __func__, true));
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	printf(D_RED"==="ORANGE"IMAGE : %ld"D_RED"==="RESET"\n", ++data->count);
	return (false);
}
