/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_fnct5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:40:39 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/13 17:16:08 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_rev(char *str, uintmax_t isnegative)
{
	uintmax_t	j;
	char		tmp;

	j = ft_strlen(str) - 1;
	while (j > isnegative)
	{
		tmp = str[isnegative];
		str[isnegative] = str[j];
		str[j] = tmp;
		j--;
		isnegative++;
	}
}

int32_t	get_10_pow(uint64_t value)
{
	int32_t	i;

	i = 0;
	while (value > 0)
	{
		++i;
		value /= 10;
	}
	return (i - 1);
}

char	*ft_utoa(uint64_t n)
{
	int32_t	i;
	char	*result;

	if (n == 0)
		return (ft_strdup("0"));
	result = ft_calloc(sizeof(char), get_10_pow(n) + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		result[i++] = (n % 10) + '0';
		n /= 10;
	}
	ft_rev(result, 0);
	return (result);
}
