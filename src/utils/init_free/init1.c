/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:20:04 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/09 15:47:17 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_coord	init_coordinate(void)
{
	t_coord	coordinate;

	coordinate.x = 0.0;
	coordinate.y = 0.0;
	coordinate.z = 0.0;
	return (coordinate);
}

t_amb	init_ambient(void)
{
	t_amb	ambient;

	ambient.color = init_color();
	ambient.brightness = 0.0;
	return (ambient);
}

t_light	*init_light(t_data *data)
{
	t_light	*light;

	light = ft_calloc(sizeof(t_light), 1);
	if (!light)
		data_malloc_error(data, __func__, false, NULL);
	light->coordinate = init_coordinate();
	light->color = init_color();
	light->brightness = 0.0;
	return (light);
}

t_parse	*init_parse(t_data *data)
{
	t_parse	*parse;

	parse = ft_calloc(1, sizeof(t_parse));
	if (!parse)
		data_malloc_error(data, __func__, false, NULL);
	parse->line = NULL;
	parse->fd = -1;
	parse->error = false;
	parse->al = false;
	parse->c = false;
	parse->l = false;
	return (parse);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		data_malloc_error(NULL, __func__, false, NULL);
	data->p = init_parse(data);
	data->objs = init_objs(data);
	data->lights = init_light(data);
	data->ambient = init_ambient();
	data->fov = 0;
	data->height = 0;
	data->width = 0;
	data->to_img = NULL;
	return (data);
}
