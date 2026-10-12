/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:17:43 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/09 15:52:12 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_cylinder(t_cylinder *cylinder)
{
	if (!cylinder)
		return ;
	if (cylinder->type)
		free (cylinder->type);
	free (cylinder);
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

void	free_light(t_light *light)
{
	if (!light)
		return ;
	free (light);
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

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_parse(data->p, true);
	free_objs(data->objs);
	free_light(data->lights);
	if (data->to_img)
		free (data->to_img);
	free (data);
	data = NULL;
}
