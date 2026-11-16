/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:33:34 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/10 09:34:17 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_sphere(t_data *data, char **obj)
{
	t_sphere	sphere;

	if (nb_arg(obj) != 4)
	{
		error_generic_rt(data->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	sphere.type = OBJ_SPHERE;
	if (valid_vector(data, &sphere.coordinate, obj[1], false))
		return ;
	if (valid_double(data, &sphere.radius, obj[2]))
		return ;
	if (valid_color(data, &sphere.color, obj[3]))
		return ;
	if (ad_data_scene_objects(&data->objs, &sphere, OBJ_SPHERE))
		data_malloc_error_parse(data, __func__, true, NULL);
	data->nb_objs++;
}

void	fill_plane(t_data *data, char **obj)
{
	t_plane	plane;

	if (nb_arg(obj) != 4)
	{
		error_generic_rt(data->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	plane.type = OBJ_PLANE;
	if (valid_vector(data, &plane.coordinate, obj[1], false))
		return ;
	if (valid_vector(data, &plane.normal, obj[2], true))
		return ;
	if (valid_color(data, &plane.color, obj[3]))
		return ;
	if (ad_data_scene_objects(&data->objs, &plane, OBJ_PLANE))
		data_malloc_error_parse(data, __func__, true, NULL);
	data->nb_objs++;
}

void	fill_cylinder(t_data *data, char **obj)
{
	t_cylinder	cylinder;

	if (nb_arg(obj) != 6)
	{
		error_generic_rt(data->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	cylinder.type = OBJ_CYLINDER;
	if (valid_vector(data, &cylinder.coordinate, obj[1], false))
		return ;
	if (valid_vector(data, &cylinder.normal, obj[2], true))
		return ;
	if (valid_double(data, &cylinder.height, obj[3]))
		return ;
	if (valid_double(data, &cylinder.diameter, obj[4]))
		return ;
	if (valid_color(data, &cylinder.color, obj[5]))
		return ;
	if (ad_data_scene_objects(&data->objs, &cylinder, OBJ_CYLINDER))
		data_malloc_error_parse(data, __func__, true, NULL);
	data->nb_objs++;
}
