/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_fnct3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:05:09 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/27 12:46:18 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static uint16_t	get_size_st(t_kind type)
{
	if (type == OBJ_SPHERE)
		return (sizeof(t_sphere));
	if (type == OBJ_PLANE)
		return (sizeof(t_plane));
	if (type == OBJ_CYLINDER)
		return (sizeof(t_cylinder));
	return (UINT16_MAX);
}

void	*ft_realloc_back(void *ptr, uintmax_t old_size, uintmax_t new_size)
{
	void	*new_ptr;

	new_ptr = ft_calloc(new_size, 1);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, ft_min(old_size, new_size));
	free(ptr);
	return (new_ptr);
}

bool	extend_fail(t_header *header, void **arr, void *new_value)
{
	void		*new_arr;

	if (header->count >= header->capacity)
	{
		new_arr = ft_extend_array_back(arr);
		if (!new_arr)
		{
			free(new_value);
			return (true);
		}
		*arr = new_arr;
		header = (t_header *)*arr - 1;
	}
	return (false);
}

bool	ad_data_scene_objects(void **arr, void *value, t_kind type)
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
	return (false);
}
