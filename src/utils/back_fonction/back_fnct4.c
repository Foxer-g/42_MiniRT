/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_fnct4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:05:09 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 18:47:43 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static uint16_t	get_size_st(t_st_type type)
{
	if (type == SPH)
		return (sizeof(t_sphere));
	if (type == PLA)
		return (sizeof(t_plane));
	if (type == CYL)
		return (sizeof(t_cylinder));
	return (UINT16_MAX);
}

bool	ad_data_scene_objs(void **arr, void *value, t_st_type type)
{
	t_header	*header;
	void		*new_value;
	size_t		size;

	size = get_size_st(type);
	new_value = ft_calloc(size, 1);
	if (!new_value)
		return (true);
	ft_memcpy(new_value, value, size);
	header = (t_header *)*arr - 1;
	if (extend_fail(header, arr, new_value))
		return (true);
	header = (t_header *)*arr - 1;
	((void **)*arr)[header->count] = new_value;
	header->count++;
	print_struct(type);
	return (false);
}
