/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_fnct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 16:58:04 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/08 16:10:30 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_sign(const char *line, int *index)
{
	int	sign;

	sign = 1;
	while (line[*index] == '+' || line[*index] == '-')
	{
		if (line[*index] == '-')
			sign *= -1;
		(*index)++;
	}
	return (sign);
}

void	*ft_realloc_back(void *ptr, uintmax_t old_size, uintmax_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, ft_min(old_size, new_size));
	free(ptr);
	return (new_ptr);
}
