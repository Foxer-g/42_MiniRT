/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:50:54 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @doc ft_min
// @kind func
// @desc Returns the smallest unsigned between a and b.
// @param a: uintmax_t, First number to compare.
// @param b: uintmax_t, Second number to compare.
// @returns uintmax_t, Minimum of a and b.
uintmax_t	ft_min(uintmax_t a, uintmax_t b)
{
	if (a < b)
		return (a);
	return (b);
}

// @doc ft_max
// @kind func
// @desc Returns the biggest unsigned between a and b.
// @param a: uintmax_t, First number to compare.
// @param b: uintmax_t, Second number to compare.
// @returns uintmax_t, Maximum of a and b.
uintmax_t	ft_max(uintmax_t a, uintmax_t b)
{
	if (a > b)
		return (a);
	return (b);
}

// @doc ft_nt_tablen
// @kind func
// @desc Returns the length of the null terminated tab tab.
// @param tab: void **, Null terminated tab to get the length of.
// @returns uintmax_t, length of tab.
uintmax_t	ft_nt_tablen(void **tab)
{
	uintmax_t	len;

	len = 0;
	while (tab && tab[len])
		len++;
	return (len);
}
