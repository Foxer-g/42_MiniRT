/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:24:14 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/16 10:43:01 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_ambient_lighting(t_data *data, t_parse *p, char **obj)
{
	if (p->al)
		error_generic_rt(data->p, ERR_ALREADY_USE, __func__);
	else if (nb_arg(obj) != 3)
		error_generic_rt(data->p, ERR_RT_INVALID_DATA, __func__);
	else if (valid_ratio(data, obj[1]))
		return ;
	else if (valid_color(data, &data->ambient.color, obj[2]))
		return ;
	p->al = true;
}

void	fill_camera(t_data *data, t_parse *p, char **obj)
{
	if (p->c)
		error_generic_rt(p, ERR_ALREADY_USE, __func__);
	else if (nb_arg(obj) != 4)
		error_generic_rt(p, ERR_RT_INVALID_DATA, __func__);
	else if (valid_vector(data, &data->camera.coordinate, obj[1], false))
		return ;
	else if (valid_vector(data, &data->camera.orient_vector, obj[2], true))
		return ;
	else if (valid_fov(data, obj[3]))
		return ;
	p->c = true;
}

void	fill_light(t_data *data, t_parse *p, char **obj)
{
	if (p->l)
	{
		error_generic_rt(data->p, ERR_ALREADY_USE, __func__);
		return ;
	}
	if (nb_arg(obj) != 4)
	{
		error_generic_rt(data->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	else if (valid_vector(data, &data->lights.coordinate, obj[1], false))
		return ;
	else if (valid_brightness(data, obj[2]))
		return ;
	else if (valid_color(data, &data->lights.color, obj[3]))
		return ;
	p->l = true;
}
