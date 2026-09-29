/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:33:34 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/29 15:03:23 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_ambient_lighting(t_data *s, t_parse *p)
{
	// int		i;

	// i = 0;
	ad_data_to_objs(s, &s->objs, p->identifier);
	// while (p->line[i] && !ft_isdigit(p->line[i]) && p->line[i] != '-')
	// 	i++;
	// if (!p->line[i])
	// 	return ;
	//  tmp = &str[i];
	// s->objs = ft_strtod(tmp, &tmp);
	// check_space(tmp, 0, str, scene);
	// s->objs = create_vec3(&tmp, scene, str);
}


void	fill_camera(t_data *s, t_parse *p)
{
	(void)s;
	(void)p;
	return ;
}

void	fill_light(t_data *s, t_parse *p)
{
	(void)s;
	(void)p;
	return ;
}

void	fill_sphere(t_data *s, t_parse *p)
{
	(void)s;
	(void)p;
	return ;
}

void	fill_plane(t_data *s, t_parse *p)
{
	(void)s;
	(void)p;
	return ;
}
