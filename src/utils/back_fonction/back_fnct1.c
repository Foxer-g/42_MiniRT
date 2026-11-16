/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_fnct1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:53:33 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/12 17:23:36 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

void	free_size_arr(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
}

void	free_nt_arr(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	leap_space(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

bool	ft_isvoid(char *line)
{
	int	i;

	i = 0;
	if (!line[0])
		return (true);
	while (line[i] && (ft_isspace(line[i]) || line[i] == '\n'))
		i++;
	if (!line[i])
		return (true);
	return (false);
}
