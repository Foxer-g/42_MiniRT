/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:17:43 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 18:48:18 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

void	free_mlx_st(t_mlx *mlx_st)
{
	if (!mlx_st)
		return ;
	if (mlx_st->win)
		mlx_destroy_window(mlx_st->mlx, mlx_st->win);
	if (mlx_st->img)
		mlx_destroy_image(mlx_st->mlx, mlx_st->img);
	if (mlx_st->mlx)
		mlx_destroy_context(mlx_st->mlx);
	free(mlx_st);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_parse(data->p, true);
	free_objs(data->objs);
	free_objs(data->scene_objs);
	free_light(data->lights);
	free_camera(data->camera);
	free_mlx_st(data->mlx_st);
	if (data->to_img)
		free (data->to_img);
	free(data);
}
