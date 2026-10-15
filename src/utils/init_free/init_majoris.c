/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_majoris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:20:04 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 18:57:11 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_parse	*init_parse(t_data *data)
{
	t_parse	*parse;

	parse = ft_calloc(sizeof(t_parse), 1);
	if (!parse)
		data_malloc_error(data, ERR_MALOC, __func__);
	parse->line = NULL;
	parse->fd = NO_FD;
	parse->error = false;
	parse->al = false;
	parse->c = false;
	parse->l = false;
	return (parse);
}

// t_mlx	*init_mlx_st(t_data *data)
// {
// 	mlx_window_create_info	info;
// 	t_mlx					*mlx_st;

// 	mlx_st = ft_calloc(sizeof(t_mlx), 1);
// 	if (!mlx_st)
// 		data_malloc_error(data, ERR_MALOC, __func__);
// 	mlx_st->mlx = mlx_init();
// 	if (!mlx_st->mlx)
// 		data_malloc_error(data, ERR_MLX, __func__);
// 	info.render_target = NULL;
// 	info.title = TITLE;
// 	info.width = data->width;
// 	info.height = data->height;
// 	info.is_fullscreen = false;
// 	info.is_resizable =false;
// 	mlx_st->win = mlx_new_window(mlx_st->mlx, &info);
// 	if (!mlx_st->win)
// 		data_malloc_error(data, ERR_WIN, __func__);
// 	return (mlx_st);
// }

// typedef struct mlx_window_create_info
// {
//     mlx_image render_target;
//     const char* title;
//     int width;
//     int height;
//     bool is_fullscreen;
//     bool is_resizable;
// } mlx_window_create_info;

void	*init_scene_objs(t_data *data)
{
	t_elem	elem;

	elem.type = PTR;
	data->scene_objs = ft_init_array_back(elem);
	if (!data->scene_objs)
		data_malloc_error(data, ERR_MALOC, __func__);
	return (data->scene_objs);
}

void	*init_objs(t_data *data)
{
	t_elem	elem;

	elem.type = PTR;
	data->objs = ft_init_array_back(elem);
	if (!data->objs)
		data_malloc_error(data, ERR_MALOC, __func__);
	return (data->objs);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		data_malloc_error(data, ERR_MALOC, __func__);
	data->height = DEF_HEIGHT;
	data->width = DEF_WIDTH;
	data->to_img = NULL;
	data->p = init_parse(data);
	init_objs(data);
	init_scene_objs(data);
	data->lights = NULL;
	data->camera = NULL;
	data->mlx_st = NULL;//init_mlx_st(data);
	return (data);
}
