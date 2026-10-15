/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:33:34 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 13:48:04 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_ambient_lighting(t_data *s, t_parse *p, char **obj)
{
	int		i;

	i = 0;
	if (p->al)
	{
		error_generic_rt(s->p, ERR_ALREADY_USE, __func__);
		return ;
	}
	if (nb_arg(obj) != 3)
	{
		error_generic_rt(s->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	if (ad_data_to_objs(&s->objs, "A", PTR, 0))
		data_malloc_error_parse(s, __func__, true, NULL);
	if (valid_ratio(s, obj[1]))
		return ;
	if (valid_color(s, obj[2]))
		return ;
	p->al = true;
}

void	fill_camera(t_data *s, char **obj)
{
	if (s->p->c)
	{
		error_generic_rt(s->p, ERR_ALREADY_USE, __func__);
		return ;
	}
	if (nb_arg(obj) != 4)
	{
		error_generic_rt(s->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	if (ad_data_to_objs(&s->objs, "C", PTR, 0))
		data_malloc_error_parse(s, __func__, true, NULL);
	if (valid_coord(s, obj[1]))
		return ;
	if (valid_vector(s, obj[2]))
		return ;
	if (valid_fov(s, obj[3]))
		return ;
	s->p->c = true;
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
	if (ad_data_to_objs(&s->objs, "L", PTR, 0))
		data_malloc_error_parse(s, __func__, true, NULL);
	else if (valid_coord(s, obj[1]))
		return ;
	else if (valid_brightness(s, obj[2]))
		return ;
	else if (valid_color(s, obj[3]))
		return ;
	p->l = true;
}

void	fill_sphere(t_data *s, char **obj)
{
	if (nb_arg(obj) != 4)
	{
		error_generic_rt(s->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	if (ad_data_to_objs(&s->objs, "s", PTR, 0))
		data_malloc_error_parse(s, __func__, true, NULL);
	if (valid_coord(s, obj[1]))
		return ;
	if (valid_double(s, obj[2]))
		return ;
	if (valid_color(s, obj[3]))
		return ;
}

void	fill_plane(t_data *s, char **obj)
{
	if (nb_arg(obj) != 4)
	{
		error_generic_rt(s->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	if (ad_data_to_objs(&s->objs, "p", PTR, 0))
		data_malloc_error_parse(s, __func__, true, NULL);
	if (valid_coord(s, obj[1]))
		return ;
	if (valid_vector(s, obj[2]))
		return ;
	if (valid_color(s, obj[3]))
		return ;
}
