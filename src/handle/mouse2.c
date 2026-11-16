/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:56:16 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/16 09:47:52 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	mouse_touch_objs_data(t_data *data, int key)
{
	void	**objs;
	double	factor;

	factor = FACTOR;
	if (key == M_SCROLL_DOWN)
		factor = -factor;
	objs = (void **)data->objs;
	if (((t_plane *)objs[data->ren->s_index])->type == OBJ_SPHERE
		&& !data->ren->stor.height && !data->ren->stor.diameter)
		((t_sphere *)objs[data->ren->s_index])->radius *= exp(factor);
	else if (((t_plane *)objs[data->ren->s_index])->type == OBJ_CYLINDER)
	{
		if (!data->ren->stor.radius && !data->ren->stor.diameter)
			((t_cylinder *)objs[data->ren->s_index])->height *= exp(factor);
		else if (!data->ren->stor.radius && !data->ren->stor.height)
			((t_cylinder *)objs[data->ren->s_index])->diameter *= exp(factor);
	}
	render(data);
}

void	drag_cursor(t_data *data)
{
	REN->offset_x += (RENM.prev_x - RENM.x);
	REN->offset_y += (RENM.prev_y - RENM.y);
	RENM.prev_x = RENM.x;
	RENM.prev_y = RENM.y;
	render(data);
}
