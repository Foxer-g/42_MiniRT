/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:32:56 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/13 14:28:13 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_img_c(t_data *data)
{
	data->img_c = ft_calloc(data->height * data->width + 1, sizeof(mlx_color));
	if (!data->img_c)
		data_malloc_error(data, ERR_MALOC, __func__);
}

void	fill_control(t_data *data)
{
	data->ren->control.d_value = 0;
	data->ren->control.p_h = 20;
	data->ren->control.p_w = 100;
	data->ren->control.ob_h = data->height - data->ren->control.p_h;
	data->ren->control.ob_w = data->width / 30;
	data->ren->control.in_h = data->height - data->ren->control.p_h;
	data->ren->control.in_w = data->width - data->width / 16;
	data->ren->control.sp = data->width / 12;
	data->ren->control.i_value = 0;
}
