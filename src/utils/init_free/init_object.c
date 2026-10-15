/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:53:01 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 18:55:10 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cylinder	add_cylinder(void **obj, uintmax_t *i)
{
	t_cylinder	cylinder;

	cylinder.type = OBJ_CYLINDER;
	*i += 1;
	cylinder.coordinate = init_coordinate(obj, i);
	cylinder.color = init_color(obj, i);
	cylinder.diameter = *(double *)obj[*i];
	cylinder.height = *(double *)obj[*i + 1];
	*i += 2;
	cylinder.normal = init_vector(obj, i);
	*i -= 1;
	return (cylinder);
}

t_plane	add_plane(void **obj, uintmax_t *i)
{
	t_plane	plane;

	plane.type = OBJ_PLANE;
	*i += 1;
	plane.coordinate = init_coordinate(obj, i);
	plane.normal = init_vector(obj, i);
	plane.color = init_color(obj, i);
	*i -= 1;
	return (plane);
}

t_sphere	add_sphere(void **obj, uintmax_t *i)
{
	t_sphere	sphere;

	sphere.type = OBJ_SPHERE;
	*i += 1;
	sphere.coordinate = init_coordinate(obj, i);
	sphere.radius = *(double *)obj[*i];
	*i += 1;
	sphere.color = init_color(obj, i);
	*i -= 1;
	return (sphere);
}

static void	init_scene_object_extend(t_data *s, void **obj, uintmax_t i)
{
	t_cylinder	cyl;

	if (!ft_strncmp(obj[i], "c", 2))
	{
		cyl = add_cylinder(obj, &i);
		if (ad_data_scene_objs(&s->scene_objs, &cyl, CYL))
			data_malloc_error(s, ERR_MALOC, __func__);
	}
}

void	init_scene_object(t_data *s, uintmax_t i)
{
	void		**obj;
	t_sphere	sph;
	t_plane		pla;

	obj = s->objs;
	while (obj[++i])
	{
		if (!ft_strncmp(obj[i], "s", 2))
		{
			sph = add_sphere(obj, &i);
			if (ad_data_scene_objs(&s->scene_objs, &sph, SPH))
				data_malloc_error(s, ERR_MALOC, __func__);
		}
		else if (!ft_strncmp(obj[i], "p", 2))
		{
			pla = add_plane(obj, &i);
			if (ad_data_scene_objs(&s->scene_objs, &pla, PLA))
				data_malloc_error(s, ERR_MALOC, __func__);
		}
		else
			init_scene_object_extend(s, obj, i);
	}
}
