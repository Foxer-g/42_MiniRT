/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:57:12 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/12 16:49:57 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static char	*ft_decimal(uint64_t decimal)
{
	int32_t	i;
	char	*result;

	result = ft_calloc(sizeof(char), 7);
	if (!result)
		return (NULL);
	i = 5;
	while (i >= 0)
	{
		result[i--] = (decimal % 10) + '0';
		decimal /= 10;
	}
	i = 5;
	while (i >= 0 && result[i] == '0')
		result[i--] = '\0';
	return (result);
}

static char	*ft_join_decimal(char *a, char *b, int8_t neg, uint64_t n)
{
	char	*result;

	result = ft_calloc(1, ft_strlen(a) + ft_strlen(b) + neg + 2);
	if (!result)
		return (NULL);
	if (neg && n)
		result[0] = '-';
	ft_strlcat(result, a, ft_strlen(a) + neg + 2);
	if (b[0])
	{
		ft_strlcat(result, ".", ft_strlen(result) + 2);
		ft_strlcat(result, b, ft_strlen(result) + ft_strlen(b) + 1);
	}
	return (result);
}

static void	check_nb(double *nb)
{
	if (*nb > 18446744073709)
		*nb = 18446744073709;
	else if (*nb < -18446744073709)
		*nb = -18446744073709;
}

char	*ft_dtoa(double n)
{
	char		*save[3];
	double		nb;
	uint64_t	cop[3];
	int8_t		negative;

	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	negative = n < 0;
	check_nb(&nb);
	cop[0] = (uint64_t)(nb * 1000000ULL + 0.5);
	cop[1] = cop[0] / 1000000ULL;
	cop[2] = cop[0] % 1000000ULL;
	save[0] = ft_utoa(cop[1]);
	if (!save[0])
		return (NULL);
	save[1] = ft_decimal(cop[2]);
	if (!save[1])
	{
		free(save[0]);
		return (NULL);
	}
	save[2] = ft_join_decimal(save[0], save[1], negative, cop[0]);
	free_size_arr(save, 2);
	return (save[2]);
}
