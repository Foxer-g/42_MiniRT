/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:32:24 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/16 10:38:33 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	check_normal(t_data *data, t_vector *vector, char **arr)
{
	char	*end;
	double	value[3];
	int		i;

	i = -1;
	while (arr[++i])
	{
		if (!arr[i][0])
			return (error_generic_rt(data->p, ERR_RT_VOID_VECTOR, __func__));
		value[i] = ft_strtod(arr[i], &end);
		if (*end && !ft_isspace(*end))
			return (error_generic_rt(data->p,
					ERR_RT_INCORECT_VECTOR, __func__));
		if (value[i] < -1 || value[i] > 1)
			return (error_generic_rt(data->p,
					ERR_RT_INVALID_ORIENT, __func__));
	}
	vector->x = value[0];
	vector->y = value[1];
	vector->z = value[2];
	return (false);
}

static bool	check_vector(t_data *data, t_vector *vector, char **arr)
{
	char	*end;
	double	value[3];
	int		i;

	i = -1;
	while (arr[++i])
	{
		if (!arr[i][0])
			return (error_generic_rt(data->p, ERR_RT_VOID_VECTOR, __func__));
		value[i] = ft_strtod(arr[i], &end);
		if (*end && !ft_isspace(*end))
			return (error_generic_rt(data->p,
					ERR_RT_INCORECT_VECTOR, __func__));
	}
	vector->x = value[0];
	vector->y = value[1];
	vector->z = value[2];
	return (false);
}

bool	valid_vector(t_data *data, t_vector *vector, char *str, bool type)
{
	char		**arr;

	arr = ft_split(str, SEP);
	if (!arr)
		data_malloc_error_parse(data, __func__, true, NULL);
	if (nb_arg(arr) != 3)
	{
		free_nt_arr(arr);
		return (error_generic_rt(data->p, ERR_RT_FORMAT_VECTOR, __func__));
	}
	if (type && check_normal(data, vector, arr))
	{
		free_nt_arr(arr);
		return (true);
	}
	else if (check_vector(data, vector, arr))
	{
		free_nt_arr(arr);
		return (true);
	}
	free_nt_arr(arr);
	return (false);
}

static bool	check_get_color(t_data *data, mlx_color *color, char **arr)
{
	int	j;
	int	i;
	int	value[3];

	i = -1;
	while (arr[++i])
	{
		j = 0;
		while (arr[i][j] && (arr[i][j] == '-' || arr[i][j] == '+'))
			j++;
		while (arr[i][j])
			if (!ft_isdigit(arr[i][j++]))
				return (error_generic_rt(data->p,
						ERR_INCORECT_COLOR, __func__));
		value[i] = ft_atoi(arr[i]);
		if (value[i] < 0 || value[i] > 255)
			return (error_generic_rt(data->p, ERR_INVALID_COLOR, __func__));
	}
	color->a = 255;
	color->r = value[0];
	color->g = value[1];
	color->b = value[2];
	color->rgba = 0;
	return (false);
}

bool	valid_color(t_data *data, mlx_color *color, char *str)
{
	char	**arr;

	arr = ft_split(str, SEP);
	if (!arr)
		data_malloc_error_parse(data, __func__, true, NULL);
	if (nb_arg(arr) != 3)
	{
		free_nt_arr(arr);
		return (error_generic_rt(data->p, ERR_RT_INVALID_DATA, __func__));
	}
	if (check_get_color(data, color, arr))
	{
		free_nt_arr(arr);
		return (true);
	}
	free_nt_arr(arr);
	return (false);
}
