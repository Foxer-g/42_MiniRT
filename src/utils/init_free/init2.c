/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:37:24 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/29 13:01:58 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	init_vector(void)
{
	t_vector	vector;

	vector.x = 0.0;
	vector.y = 0.0;
	vector.z = 0.0;
	return (vector);
}

t_plane	*init_plane(t_data *data)
{
	t_plane	*plane;

	plane = ft_calloc(sizeof(t_plane), 1);
	if (!plane)
		data_malloc_error(data, ERR_INIT_PL);
	plane->type = NULL;
	plane->coordinate = init_coordinate();
	plane->color = init_color();
	plane->normal = init_vector();
	return (plane);
}

t_sphere	*init_sphere(t_data *data)
{
	t_sphere	*sphere;

	sphere = ft_calloc(sizeof(t_sphere), 1);
	if (!sphere)
		data_malloc_error(data, ERR_INIT_SP);
	sphere->type = NULL;
	sphere->coordinate = init_coordinate();
	sphere->color = init_color();
	sphere->radius = 0.0;
	return (sphere);
}

t_cylinder	*init_cylinder(t_data *data)
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(sizeof(t_cylinder), 1);
	if (!cylinder)
		data_malloc_error(data, ERR_INIT_CY);
	cylinder->type = NULL;
	cylinder->coordinate = init_coordinate();
	cylinder->color = init_color();
	cylinder->diameter = 0.0;
	cylinder->height = 0.0;
	cylinder->normal = init_vector();
	return (cylinder);
}

void	*init_objs(t_data *data)
{
	t_elem	elem;

	elem.type = PTR;
	data->objs = ft_init_array_back(elem);
	if (!data->objs)
		data_malloc_error(data, ERR_INIT_OB);
	return (data->objs);
}
