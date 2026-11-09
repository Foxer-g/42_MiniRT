/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:08:58 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/26 13:29:22 by ethutin-         ###   ########.fr       */
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
		if (!ft_isdigit(fov[0][i++]))
			return (error_generic_rt(s->p, ERR_RT_INVALID_FOV, __func__));
	data = ft_atoi(fov[0]);
	if (data < 0 || data > 180)
		return (error_generic_rt(s->p, ERR_RT_INCORECT_FOV, __func__));
	s->camera.fov = data;
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

static bool	check_ratio(t_data *s, char *str, char *end, double ratio)
{
	if (str == end)
		return (error_generic_rt(s->p, ERR_RT_NO_RATIO, __func__));
	if (ratio < 0.0 || ratio > 1.0)
		return (error_generic_rt(s->p, ERR_RT_INVALID_RATIO, __func__));
	if (*end && !ft_isspace(*end))
		return (error_generic_rt(s->p, ERR_RT_INCORECT_RATIO, __func__));
	return (false);
}

bool	valid_ratio(t_data *s, char *str)
{
	char	**ratio;
	char	*end;
	double	data;

	ratio = ft_split(str, SEP);
	if (!ratio)
		data_malloc_error_parse(s, __func__, true, NULL);
	if (nb_arg(ratio) != 1)
	{
		free_nt_arr(ratio);
		return (error_generic_rt(s->p, ERR_RT_FORMAT_RATIO, __func__));
	}
	data = ft_strtod(str, &end);
	if (check_ratio(s, str, end, data))
	{
		free_nt_arr(ratio);
		return (true);
	}
	free_nt_arr(ratio);
	s->ambient.brightness = data;
	return (false);
}
