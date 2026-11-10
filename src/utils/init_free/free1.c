/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:17:43 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/10 14:55:56 by toespino         ###   ########.fr       */
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

static	void	free_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->mlx)
		mlx_destroy_context(mlx->mlx);
	free(mlx);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_parse(data->p, true);
	free_objs(data->objs);
	free_mlx(data->mlx);
	free_mlx_map(data->ren);
	if (data->img_c)
		free (data->img_c);
	free(data);
}
