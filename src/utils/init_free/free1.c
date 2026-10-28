/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:17:43 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 10:04:13 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	free_mlx_map(t_ren *map)
{
	if (!map)
		return ;
	free (map);
}

void	free_objs(void *objs)
{
	t_header	*header;
	uintmax_t	i;

	if (!objs)
		return ;
	header = (t_header *)objs - 1;
	i = -1;
	while (++i < header->count)
		free(((void **)objs)[i]);
	free(header);
}

void	free_parse(t_parse *parse, bool complete)
{
	if (!parse)
		return ;
	if (parse->obj)
		free_nt_arr(parse->obj);
	if (parse->line)
		free(parse->line);
	parse->obj = NULL;
	parse->line = NULL;
	if (complete)
	{
		if (parse->fd >= 0)
			close(parse->fd);
		free(parse);
		parse = NULL;
	}
}

static	void	free_m_st(t_mlx *m_st)
{
	if (!m_st)
		return ;
	if (m_st->win)
		mlx_destroy_window(m_st->mlx, m_st->win);
	if (m_st->img)
		mlx_destroy_image(m_st->mlx, m_st->img);
	if (m_st->mlx)
		mlx_destroy_context(m_st->mlx);
	free(m_st);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_parse(data->p, true);
	free_objs(data->objs);
	free_m_st(data->m_st);
	free_mlx_map(data->ren);
	if (data->img_c)
		free (data->img_c);
	if (data->to_image)
		free (data->to_image);
	free(data);
}
