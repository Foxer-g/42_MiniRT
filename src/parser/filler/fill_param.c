/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:24:14 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 11:23:14 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_ambient_lighting(t_data *s, t_parse *p, char **obj)
{
	int		i;

	i = 0;
	if (p->al)
		error_generic_rt(s->p, ERR_ALREADY_USE, __func__);
	else if (nb_arg(obj) != 3)
		error_generic_rt(s->p, ERR_RT_INVALID_DATA, __func__);
	else if (valid_ratio(s, obj[1]))
		return ;
	else if (valid_color(s, &s->ambient.color, obj[2]))
		return ;
	p->al = true;
}

void	fill_camera(t_data *s, t_parse *p, char **obj)
{
	if (p->c)
		error_generic_rt(p, ERR_ALREADY_USE, __func__);
	else if (nb_arg(obj) != 4)
		error_generic_rt(p, ERR_RT_INVALID_DATA, __func__);
	else if (valid_vector(s, &s->camera.coordinate, obj[1], false))
		return ;
	else if (valid_vector(s, &s->camera.orient_vector, obj[2], true))
		return ;
	else if (valid_fov(s, obj[3]))
		return ;
	p->c = true;
}

void	fill_light(t_data *s, t_parse *p, char **obj)
{
	if (p->l)
	{
		error_generic_rt(s->p, ERR_ALREADY_USE, __func__);
		return ;
	}
	if (nb_arg(obj) != 4)
	{
		error_generic_rt(s->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	else if (valid_vector(s, &s->lights.coordinate, obj[1], false))
		return ;
	else if (valid_brightness(s, obj[2]))
		return ;
	else if (valid_color(s, &s->lights.color, obj[3]))
		return ;
	p->l = true;
}
