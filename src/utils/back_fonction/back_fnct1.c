/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_fnct1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:53:33 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/29 11:41:03 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	only_quote(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		if (line[i] != '\'' && line[i] != '\"')
			return (0);
	return (1);
}

int	full_void(char *line)
{
	int	i;

	i = -1;
	if (line)
	{
		while (line[++i])
			if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
				return (0);
	}
	return (1);
}

int	nb_arg(char **ar)
{
	int	i;

	if (!ar)
		return (0);
	i = 0;
	while (ar[i])
		i++;
	return (i);
}

bool	valid_ratio (double ratio)
{
	return (ratio < 0.0 || ratio > 1.0);
}
bool 	valid_color(t_color color)
{
	return ((color.r < (int8_t)0 || color.r > (int8_t)255)
	|| (color.g < (int8_t)0 || color.g > (int8_t)255)
	|| (color.b < (int8_t)0 || color.b > (int8_t)255));
}

