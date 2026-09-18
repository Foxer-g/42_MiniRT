/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:25:06 by rboutlo           #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_atoi(const char *str)
{
	int64_t		result;
	int8_t		negative;
	int32_t		i;

	negative = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = 0;
	while (ft_isdigit(str[i]) && result < INT32_MAX)
		result = (result * 10) + (str[i++] - '0');
	if (result > INT32_MAX + negative)
		errno = EINVAL;
	if (negative)
		return (-result);
	return (result);
}

static void	ft_rev(char *str, uintmax_t isnegative)
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

static int32_t	get_10_pow(int64_t value)
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

char	*ft_itoa(int32_t n)
{
	int32_t	i;
	int64_t	nb;
	char	*result;
	int8_t	negative;

	nb = n;
	negative = nb < 0;
	if (negative)
		nb = -nb;
	if (n == 0)
		result = ft_strdup("0");
	else
		result = ft_calloc(negative + get_10_pow(nb) + 1 + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	if (negative)
		result[i++] = '-';
	while (nb > 0)
	{
		result[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	ft_rev(result, negative);
	return (result);
}
