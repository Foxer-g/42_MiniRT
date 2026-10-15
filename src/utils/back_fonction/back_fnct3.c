/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_fnct3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 13:22:42 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 18:47:16 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static uint16_t	get_size(t_type type)
{
	if (type == N8)
		return (sizeof(uint8_t));
	if (type == N16)
		return (sizeof(uint16_t));
	if (type == N32)
		return (sizeof(uint32_t));
	if (type == N64)
		return (sizeof(uint64_t));
	if (type == PTR)
		return (sizeof(void *));
	if (type == FLOAT)
		return (sizeof(float));
	if (type == DOUBLE)
		return (sizeof(double));
	if (type == LDOUBLE)
		return (sizeof(long double));
	return (UINT16_MAX);
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

bool	ad_data_to_objs(void **arr, void *value, t_type type, size_t size)
{
	t_header	*header;
	void		*new_value;

	if (type == PTR)
	{
		new_value = ft_strdup(value);
		if (!new_value)
			return (true);
	}
	else
	{
		size = get_size(type);
		new_value = ft_calloc(size, 1);
		if (!new_value)
			return (true);
		ft_memcpy(new_value, value, size);
	}
	header = (t_header *)*arr - 1;
	if (extend_fail(header, arr, new_value))
		return (true);
	header = (t_header *)*arr - 1;
	((void **)*arr)[header->count] = new_value;
	header->count++;
	print_value(new_value, type);
	return (false);
}

void	*ft_init_array_back(t_elem elem)
{
	t_header	*result;

	result = malloc(get_size(elem.type) * ARR_DEFAULT_SIZE
			+ sizeof(t_header));
	if (!result)
		return (NULL);
	ft_bzero(result, get_size(elem.type) * ARR_DEFAULT_SIZE
		+ sizeof(t_header));
	result->type = elem.type;
	result->count = 0;
	result->capacity = ARR_DEFAULT_SIZE;
	return (result + 1);
}

void	*ft_extend_array_back(void **arr)
{
	t_header	*header;
	t_header	*new;
	uintmax_t	old_size;
	uintmax_t	new_size;
	uintmax_t	new_capacity;

	header = (t_header *)*arr - 1;
	new_capacity = header->capacity * 2;
	old_size = sizeof(t_header)
		+ get_size(header->type) * header->capacity;
	new_size = sizeof(t_header)
		+ get_size(header->type) * new_capacity;
	new = ft_realloc_back(header, old_size, new_size);
	if (!new)
		return (NULL);
	new->capacity = new_capacity;
	return (new + 1);
}
