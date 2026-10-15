/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:40:23 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 18:48:53 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_amb	init_ambient(void **objs, uintmax_t	*i)
{
	t_amb	ambient;

	*i += 1;
	ambient.color = init_color(objs, i);
	ambient.brightness = *(double *)objs[*i];
	return (ambient);
}

t_cam	*init_camera(t_data *data, uintmax_t *i)
{
	void	**obj;
	t_cam	*cam;

	obj = (void **)data->objs;
	cam = ft_calloc(sizeof(t_cam), 1);
	if (!cam)
		data_malloc_error(data, ERR_MALOC, __func__);
	*i += 1;
	cam->coordinate = init_coordinate(obj, i);
	cam->vector = init_vector(obj, i);
	cam->fov = *(int32_t *)obj[*i];
	return (cam);
}

t_light	*init_light(t_data *data, uintmax_t *i)
{
	void	**obj;
	t_light	*light;

	obj = (void **)data->objs;
	light = ft_calloc(sizeof(t_light), 1);
	if (!light)
		data_malloc_error(data, ERR_MALOC, __func__);
	*i += 1;
	light->coordinate = init_coordinate(obj, i);
	light->brightness = *(double *)obj[*i];
	*i += 1;
	light->color = init_color(obj, i);
	return (light);
}

void	init_scene(t_data *s)
{
	void		**obj;
	uintmax_t	i;

	obj = s->objs;
	i = 0;
	while (obj[i])
	{
		if (!ft_strncmp(obj[i], "L", 2))
			s->lights = init_light(s, &i);
		else if (!ft_strncmp(obj[i], "C", 2))
			s->camera = init_camera(s, &i);
		else if (!ft_strncmp(obj[i], "A", 2))
			s->ambient = init_ambient(obj, &i);
		i++;
	}
}
