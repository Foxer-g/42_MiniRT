/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:47:02 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/16 09:47:28 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	zoom_mouse(t_data *data, t_ren *r, int key)
{
	double	factor;

	factor = FACTOR;
	if (key == M_SCROLL_DOWN)
		factor = -factor;
	r->offset_x = r->mouse.x - (r->mouse.x - r->offset_x)
		* ((r->scale * exp(factor)) / r->scale);
	r->offset_y = r->mouse.y - (r->mouse.y - r->offset_y)
		* ((r->scale * exp(factor)) / r->scale);
	r->scale *= exp(factor);
	printf(ORANGE"ZOOM_MOUSE"RESET"\n");
	render(data);
}

void	z_scale_mouse(t_data *data, int key)
{
	double	factor;

	factor = FACTOR;
	if (key == M_SCROLL_DOWN)
		factor = -factor;
	REN->z_scale *= exp(factor);
	if (REN->z_scale <= Z_MIN)
		REN->z_scale = Z_MIN;
	if (REN->z_scale >= Z_MAX)
		REN->z_scale = Z_MAX;
	printf(ORANGE"Z_SCALE"RESET"\n");
	render(data);
}

void	central_scroll(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_mouse_get_pos(data->mlx->mlx, &RENM.x, &RENM.y);
	if ((key == M_SCROLL_DOWN || key == M_SCROLL_UP)
		&& !RENS.space && !RENS.ctrl)
		zoom_mouse(data, REN, key);
	else if ((key == M_SCROLL_DOWN || key == M_SCROLL_UP)
		&& RENS.space && !RENS.ctrl)
		z_scale_mouse(data, key);
	else if (RENS.ctrl && (RENS.radius || RENS.height || RENS.diameter)
		&& (key == M_SCROLL_DOWN || key == M_SCROLL_UP))
		mouse_touch_objs_data(data, key);
	else if (RENS.ctrl && (key == M_SCROLL_DOWN || key == M_SCROLL_UP))
		select_objs(data, key);
}

void	central_mouse_up(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == M_LEFT && RENM.l_click)
		RENM.l_click = false;
	if (key == M_MIDDLE && RENM.m_click)
		RENM.m_click = false;
}

void	central_mouse(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_mouse_get_pos(data->mlx->mlx, &RENM.x, &RENM.y);
	if (key == M_LEFT && !RENM.l_click)
	{
		RENM.l_click = true;
		RENM.prev_x = RENM.x;
		RENM.prev_y = RENM.y;
	}
	else if (!RENS.ctrl && key == M_LEFT && RENM.l_click)
		drag_cursor(data);
}
