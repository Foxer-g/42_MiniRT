/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:47:02 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 17:12:25 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	drag_cursor(t_data *data)
{
	update_pos(data, 0, data->ren->mouse->cop_x - data->ren->mouse->x);
	update_pos(data, 1, data->ren->mouse->cop_y - data->ren->mouse->y);
	data->ren->mouse->cop_x = data->ren->mouse->x;
	data->ren->mouse->cop_y = data->ren->mouse->y;
	printf(ORANGE"DRAG_CURSOR"RESET"\n");
	renderer(data);
}

void	zoom_mouse(t_data *data, t_ren *r, int key)//non fonctionnelle attendre que les champs calculatoire soit remplis
{
	if (key == M_SCROLL_DOWN)
	{
		r->offset_x = r->mouse->x - (r->mouse->x - r->offset_x)
			* ((r->scale * MINUS_SCALE) / r->scale);
		r->offset_y = r->mouse->y - (r->mouse->y - r->offset_y)
			* ((r->scale * MINUS_SCALE) / r->scale);
		r->scale *= MINUS_SCALE;
	}
	else if (key == M_SCROLL_UP)
	{
		r->offset_x = r->mouse->x - (r->mouse->x - r->offset_x)
			* ((r->scale * PLUS_SCALE) / r->scale);
		r->offset_y = r->mouse->y - (r->mouse->y - r->offset_y)
			* ((r->scale * PLUS_SCALE) / r->scale);
		r->scale *= PLUS_SCALE;
	}
	// printf(ORANGE"ZOOM_MOUSE"RESET"\n");
	renderer(data);
}

void	z_scale_mouse(t_data *data, int key)//non fonctionnelle attendre que les champs calculatoire soit remplis
{
	if (key == M_SCROLL_DOWN)
	{
		data->ren->z_scale *= MINUS_SCALE;
		if (data->ren->z_scale <= Z_MIN)
			data->ren->z_scale = Z_MIN;
	}
	else if (key == M_SCROLL_UP)
	{
		data->ren->z_scale /= MINUS_SCALE;
		if (data->ren->z_scale >= Z_MAX)
			data->ren->z_scale = Z_MAX;
	}
	printf(ORANGE"Z_SCALE_MOUSE"RESET"\n");
	renderer(data);
}

void	central_mouse_up(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == M_LEFT)
		data->ren->mouse->left_click = 0;
	if (key == M_MIDDLE)
		data->ren->mouse->middle_click = 0;
}

void	central_mouse(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_mouse_get_pos(data->m_st->mlx, &data->ren->mouse->x, \
&data->ren->mouse->y);
	if ((key == M_SCROLL_DOWN || key == M_SCROLL_UP)
		&& data->ren->click_space)
		z_scale_mouse(data, key);
	else if (key == M_SCROLL_DOWN || key == M_SCROLL_UP)
		zoom_mouse(data, data->ren, key);
	else if (key == M_LEFT && !data->ren->mouse->left_click)
	{
		data->ren->mouse->left_click = true;
		data->ren->mouse->cop_x = data->ren->mouse->x;
		data->ren->mouse->cop_y = data->ren->mouse->y;
	}
	else if (key == M_LEFT && data->ren->mouse->left_click)
		drag_cursor(data);
}
