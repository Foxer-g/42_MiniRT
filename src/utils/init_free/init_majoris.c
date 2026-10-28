/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_majoris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:20:04 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 15:57:51 by ethutin-         ###   ########.fr       */
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

void	init_m_st(t_data *data)
{
	mlx_window_create_info	info;
	t_mlx					*m_st;

	m_st = ft_calloc(sizeof(t_mlx), 1);
	if (!m_st)
		data_malloc_error(data, ERR_MALOC, __func__);
	m_st->mlx = mlx_init();
	if (!m_st->mlx)
		data_malloc_error(data, ERR_MLX, __func__);
	info.title = TITLE;
	info.width = data->width;
	info.height = data->height;
	info.render_target = NULL;
	info.is_fullscreen = false;
	info.is_resizable = false;
	m_st->win = mlx_new_window(m_st->mlx, &info);
	if (!m_st->win)
		data_malloc_error(data, ERR_WIN, __func__);
	data->m_st = m_st;
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
	data->img_c = NULL;
	data->m_st = NULL;
	data->height = DEF_HEIGHT;
	data->width = DEF_WIDTH;
	data->to_image = NULL;
	return (data);
}
