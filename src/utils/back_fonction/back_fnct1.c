/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc_gen1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:53:33 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/18 10:59:20 by ethutin-         ###   ########.fr       */
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
