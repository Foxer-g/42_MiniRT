/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:52:35 by toespino          #+#    #+#             */
/*   Updated: 2026/10/28 17:06:04 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// t_nc	get_color(t_vector point, t_data *scene, uint64_t index, t_vector normal)
// {
// 	uint64_t	i;
// 	double		tmp;
// 	t_color		new_color;
// 	t_vector	light_ray;
// 	t_nc		res;

// 	i = -1;
// 	res = (t_nc){0};
// 	while (scene.lights[++i])
// 	{
// 		light_ray = vector_sub(scene.lights[i].coordinate, normal);
// 		tmp = ft_dmax(0.0, vector_dot(normal, light_ray));
// 		if (tmp != 0.0)
// 		{
// 			if (!intersect_ray(light_ray, index, scene))
// 			{
// 				new_color = color_in(OBJ.color, LIGHT.color, tmp, LIGHT.bright);
// 				light_add(&res, new_color);
// 			}
// 		}
// 		res += tmp;
// 	}
// 	return (res);
// }

t_nc	get_color(t_vector point, t_data *scene, uint64_t index,
		t_vector normal)
{
	uint64_t	i;
	double		tmp;
	t_color		new_color;
	t_vector	light_ray;
	t_nc		res;

	i = -1;
	res = (t_nc){0};
	while (i < 2)
	{
		light_ray = vector_sub(LIGHT.coordinate, point);
		tmp = ft_dmax(0.0, vector_dot(normal, light_ray));
		if (tmp > 0.0)
		{
			if (!intersect_ray(light_ray, index, scene))
			{
				new_color = color_incident(OBJ.color, LIGHT.color, \
tmp, LIGHT.brightness);
				light_add(&res, new_color);
			}
		}
	}
	return (res);
}
