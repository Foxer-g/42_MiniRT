/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:33:34 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 11:23:38 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_sphere(t_data *s, char **obj)
{
	t_sphere	sphere;

	if (nb_arg(obj) != 4)
	{
		error_generic_rt(s->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	sphere.type = OBJ_SPHERE;
	if (valid_vector(s, &sphere.coordinate, obj[1], false))
		return ;
	if (valid_double(s, &sphere.radius, obj[2]))
		return ;
	if (valid_color(s, &sphere.color, obj[3]))
		return ;
	if (ad_data_scene_objects(&s->objs, &sphere, OBJ_SPHERE))
		data_malloc_error_parse(s, __func__, true, NULL);
}

void	fill_plane(t_data *s, char **obj)
{
	t_plane	plane;

	if (nb_arg(obj) != 4)
	{
		error_generic_rt(s->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	plane.type = OBJ_PLANE;
	if (valid_vector(s, &plane.coordinate, obj[1], false))
		return ;
	if (valid_vector(s, &plane.normal, obj[2], true))
		return ;
	if (valid_color(s, &plane.color, obj[3]))
		return ;
	if (ad_data_scene_objects(&s->objs, &plane, OBJ_PLANE))
		data_malloc_error_parse(s, __func__, true, NULL);
}

void	fill_cylinder(t_data *s, char **obj)
{
	t_cylinder	cylinder;

	if (nb_arg(obj) != 6)
	{
		error_generic_rt(s->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	cylinder.type = OBJ_CYLINDER;
	if (valid_vector(s, &cylinder.coordinate, obj[1], false))
		return ;
	if (valid_vector(s, &cylinder.normal, obj[2], true))
		return ;
	if (valid_double(s, &cylinder.height, obj[3]))
		return ;
	if (valid_double(s, &cylinder.diameter, obj[4]))
		return ;
	if (valid_color(s, &cylinder.color, obj[5]))
		return ;
	if (ad_data_scene_objects(&s->objs, &cylinder, OBJ_CYLINDER))
		data_malloc_error_parse(s, __func__, true, NULL);
}

// void	fill_triangle(t_data *s, char **obj)//a terminer apres la manda
// {
// 	t_triangle triangle;

// 	if (ad_data_scene_objects(&s->objs, &triangle, TRI))
// 		data_malloc_error_parse(s, __func__, true, NULL);
// }
