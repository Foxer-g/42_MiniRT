/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_majoris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:20:04 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/11 14:50:45 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_parse(t_data *data)
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
	data->p = parse;
}

void init_mlx(t_data *data)
{
    mlx_window_create_info info;
    t_mlx *m;

    m = ft_calloc(1, sizeof(t_mlx));
    if (!m)
        data_malloc_error(data, ERR_MALOC, __func__);
    data->mlx = m;
    m->mlx = mlx_init();
    if (!m->mlx)
        data_malloc_error(data, ERR_MLX, __func__);
    info = (mlx_window_create_info){ .render_target = NULL, .title = TITLE,
        .width = data->width, .height = data->height,
        .is_fullscreen = false, .is_resizable = false};
    m->win = mlx_new_window(m->mlx, &info);
    if (!m->win)
        data_malloc_error(data, ERR_WIN, __func__);
}

void	init_objs(t_data *data)
{
	t_elem	elem;

	elem.type = PTR;
	data->objs = ft_init_array_back(elem);
	if (!data->objs)
		data_malloc_error(data, ERR_MALOC, __func__);
}

void	init_ren(t_data *data)
{
	t_ren	*ren;

	ren = ft_calloc(sizeof(t_ren), 1);
	if (!ren)
		data_malloc_error(data, ERR_MALOC, __func__);
	ren->offset_x = 0;
	ren->offset_y = 0;
	ren->offset_z = 0;
	ren->scale = 1;
	ren->z_scale = 1;
	ren->alpha = DEFAULT_ALPHA;
	ren->beta = DEFAULT_BETA;
	ren->gamma = 0.0;
	ren->click_space = false;
	ren->full = false;
	data->ren = ren;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		data_malloc_error(data, ERR_MALOC, __func__);
	init_parse(data);
	init_objs(data);
	init_ren(data);
	data->img_c = ft_calloc(DEF_HEIGHT * DEF_WIDTH + 1, sizeof(mlx_color));
	if (!data->img_c)
		data_malloc_error(data, ERR_MALOC, __func__);
	data->mlx = NULL;
	data->height = DEF_HEIGHT;
	data->width = DEF_WIDTH;
	return (data);
}
