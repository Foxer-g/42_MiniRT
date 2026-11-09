/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:32:24 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 17:14:33 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	check_normal(t_data *s, t_vector *vector, char **arr)
{
	char	*end;
	double	data[3];
	int		i;

	i = -1;
	while (arr[++i])
	{
		if (!arr[i][0])
			return (error_generic_rt(s->p, ERR_RT_VOID_VECTOR, __func__));
		data[i] = ft_strtod(arr[i], &end);
		if (*end && !ft_isspace(*end))
			return (error_generic_rt(s->p, ERR_RT_INCORECT_VECTOR, __func__));
		if (data[i] < -1 || data[i] > 1)
			return (error_generic_rt(s->p, ERR_RT_INVALID_ORIENT, __func__));
	}
	vector->x = data[0];
	vector->y = data[1];
	vector->z = data[2];
	return (false);
}

static bool	check_vector(t_data *s, t_vector *vector, char **arr)
{
	char	*end;
	double	data[3];
	int		i;

	i = -1;
	while (arr[++i])
	{
		if (!arr[i][0])
			return (error_generic_rt(s->p, ERR_RT_VOID_VECTOR, __func__));
		data[i] = ft_strtod(arr[i], &end);
		if (*end && !ft_isspace(*end))
			return (error_generic_rt(s->p, ERR_RT_INCORECT_VECTOR, __func__));
	}
	vector->x = data[0];
	vector->y = data[1];
	vector->z = data[2];
	return (false);
}

bool	valid_vector(t_data *s, t_vector *vector, char *str, bool type)
{
	char		**arr;

	arr = ft_split(str, SEP);
	if (!arr)
		data_malloc_error_parse(s, __func__, true, NULL);
	if (nb_arg(arr) != 3)
	{
		free_nt_arr(arr);
		return (error_generic_rt(s->p, ERR_RT_FORMAT_VECTOR, __func__));
	}
	if (type && check_normal(s, vector, arr))
	{
		free_nt_arr(arr);
		return (true);
	}
	else if (check_vector(s, vector, arr))
	{
		free_nt_arr(arr);
		return (true);
	}
	free_nt_arr(arr);
	return (false);
}

static bool	check_get_color(t_data *s, t_color *color, char **arr)
{
	int	j;
	int	i;
	int	data[3];

	i = -1;
	while (arr[++i])
	{
		j = 0;
		while (arr[i][j] && (arr[i][j] == '-' || arr[i][j] == '+'))
			j++;
		while (arr[i][j])
			if (!ft_isdigit(arr[i][j++]))
				return (error_generic_rt(s->p, ERR_INCORECT_COLOR, __func__));
		data[i] = ft_atoi(arr[i]);
		if (data[i] < 0 || data[i] > 255)
			return (error_generic_rt(s->p, ERR_INVALID_COLOR, __func__));
	}
	color->r = data[0];
	color->g = data[1];
	color->b = data[2];
	return (false);
}

bool	valid_color(t_data *s, t_color *color, char *str)
{
	char	**arr;

	arr = ft_split(str, SEP);
	if (!arr)
		data_malloc_error_parse(s, __func__, true, NULL);
	if (nb_arg(arr) != 3)
	{
		free_nt_arr(arr);
		return (error_generic_rt(s->p, ERR_RT_INVALID_DATA, __func__));
	}
	if (check_get_color(s, color, arr))
	{
		free_nt_arr(arr);
		return (true);
	}
	free_nt_arr(arr);
	return (false);
}
