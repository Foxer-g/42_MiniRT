/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:32:24 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/14 17:44:00 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	get_coord(t_data *s, char **coord, int i)
{
	char	*end;
	double	data;

	data = ft_strtod(coord[i], &end);
	if (!coord[i][0])
		return (error_generic_rt(s->p, ERR_RT_VOID_COORD, __func__));
	else if (*end && !ft_isspace(*end))
		return (error_generic_rt(s->p, ERR_RT_INCORECT_COORD, __func__));
	else if (ad_data_to_objs(&s->objs, &data, DOUBLE, 0))
		data_malloc_error_parse(s, __func__, true, coord);
	return (false);
}

bool	valid_coord(t_data *s, char *str)
{
	char	**coord;
	int		i;

	i = -1;
	coord = ft_split(str, SEP);
	if (!coord)
		data_malloc_error_parse(s, __func__, true, NULL);
	else if (nb_arg(coord) != 3)
		return (error_generic_rt(s->p, ERR_RT_FORMAT_COORD, __func__));
	while (coord[++i])
	{
		if (get_coord(s, coord, i))
		{
			free_nt_arr(coord);
			return (true);
		}
	}
	free_nt_arr(coord);
	return (false);
}

static bool	verif_color(t_data *s, char **color)
{
	int	j;
	int	i;
	int	data;

	i = 0;
	while (color[i])
	{
		j = 0;
		while (color[i][j] && (color[i][j] == '-' || color[i][j] == '+'))
			j++;
		while (color[i][j])
		{
			if (!ft_isdigit(color[i][j]))
				return (error_generic_rt(s->p, ERR_INCORECT_COLOR, __func__));
			j++;
		}
		data = ft_atoi(color[i]);
		if (data < 0 || data > 255)
			return (error_generic_rt(s->p, ERR_INVALID_COLOR, __func__));
		else if (ad_data_to_objs(&s->objs, &data, N32, 0))
			data_malloc_error_parse(s, __func__, true, color);
		i++;
	}
	return (false);
}

bool	valid_color(t_data *s, char *str)
{
	char	**color;

	color = ft_split(str, SEP);
	if (!color)
		data_malloc_error_parse(s, __func__, true, NULL);
	if (nb_arg(color) != 3)
	{
		free_nt_arr(color);
		return (error_generic_rt(s->p, ERR_RT_INVALID_DATA, __func__));
	}
	if (verif_color(s, color))
	{
		free_nt_arr(color);
		return (true);
	}
	free_nt_arr(color);
	return (false);
}
