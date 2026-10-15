/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:08:58 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/14 17:44:20 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	check_fov(t_data *s, char **fov)
{
	int	i;
	int	data;

	i = 0;
	while (fov[0][i] && (fov[0][i] == '-' || fov[0][i] == '+'))
		i++;
	while (fov[0][i])
	{
		if (!ft_isdigit(fov[0][i]))
			return (error_generic_rt(s->p, ERR_RT_INVALID_FOV, __func__));
		i++;
	}
	data = ft_atoi(fov[0]);
	if (data < 0 || data > 180)
		return (error_generic_rt(s->p, ERR_RT_INCORECT_FOV, __func__));
	else if (ad_data_to_objs(&s->objs, &data, N32, 0))
		data_malloc_error_parse(s, __func__, true, fov);
	return (false);
}

bool	valid_fov(t_data *s, char *camera)
{
	char	**fov;

	fov = ft_split(camera, SEP);
	if (!fov)
		data_malloc_error_parse(s, __func__, true, NULL);
	else if (nb_arg(fov) != 1)
	{
		free_nt_arr(fov);
		return (error_generic_rt(s->p, ERR_RT_FORMAT_FOV, __func__));
	}
	else if (check_fov(s, fov))
	{
		free_nt_arr(fov);
		return (true);
	}
	free_nt_arr(fov);
	return (false);
}

static bool	get_vector(t_data *s, char **vector, int i)
{
	char	*end;
	double	data;

	data = ft_strtod(vector[i], &end);
	if (!vector[i][0])
		return (error_generic_rt(s->p, ERR_RT_VOID_VECTOR, __func__));
	else if (*end && !ft_isspace(*end))
		return (error_generic_rt(s->p, ERR_RT_INCORECT_VECTOR, __func__));
	else if (ad_data_to_objs(&s->objs, &data, DOUBLE, 0))
		data_malloc_error_parse(s, __func__, true, vector);
	return (false);
}

bool	valid_vector(t_data *s, char *str)
{
	char	**vector;
	int		i;

	vector = ft_split(str, SEP);
	if (!vector)
		data_malloc_error_parse(s, __func__, true, NULL);
	if (nb_arg(vector) != 3)
	{
		free_nt_arr(vector);
		return (error_generic_rt(s->p, ERR_RT_FORMAT_VECTOR, __func__));
	}
	i = 0;
	while (vector[i])
	{
		if (get_vector(s, vector, i))
		{
			free_nt_arr(vector);
			return (true);
		}
		i++;
	}
	free_nt_arr(vector);
	return (false);
}
