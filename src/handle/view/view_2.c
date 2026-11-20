/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:34:44 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/16 16:46:50 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	view_message(t_data *data, char *msg, uint32_t w, uint32_t h)
{
	mlx_string_put(data->mlx->mlx, data->mlx->win, w,
		(h - (++data->ren->control.level * data->ren->control.p_h)),
		(mlx_color){.rgba = RGBA_ORANGE}, msg);
}

void	view_plane(t_data *data, void **objs, uint32_t w, uint32_t h)
{
	view_coordinate(data,
		((t_plane *)objs[data->ren->s_index])->coordinate, w, h);
	view_color(data,
		((t_plane *)objs[data->ren->s_index])->color, w, h);
	view_normal(data,
		((t_plane *)objs[data->ren->s_index])->normal, w, h);
}

void	view_sphere(t_data *data, void **objs, uint32_t w, uint32_t h)
{
	view_coordinate(data,
		((t_sphere *)objs[data->ren->s_index])->coordinate, w, h);
	view_color(data, ((t_sphere *)objs[data->ren->s_index])->color, w, h);
	RENC.d_value = ((t_sphere *)objs[data->ren->s_index])->radius;
	view_double_value(data, "1 : Radius :", w, h);
}

void	view_cylinder(t_data *data, void **objs, uint32_t w, uint32_t h)
{
	view_coordinate(data,
		((t_cylinder *)objs[data->ren->s_index])->coordinate, w, h);
	view_color(data, ((t_cylinder *)objs[data->ren->s_index])->color, w, h);
	view_normal(data, ((t_cylinder *)objs[data->ren->s_index])->normal, w, h);
	RENC.d_value = ((t_cylinder *)objs[data->ren->s_index])->height;
	view_double_value(data, "2 : Height :", w, h);
	RENC.d_value = ((t_cylinder *)objs[data->ren->s_index])->diameter;
	view_double_value(data, "1 : Diameter :", w, h);
}
