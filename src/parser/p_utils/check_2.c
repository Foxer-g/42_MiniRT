/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:08:09 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/27 10:46:35 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	get_double(t_data *s, double *data, char *str)
{
	char	**arr;
	char	*end;

	*data = 0.0;
	arr = ft_split(str, SEP);
	if (!arr)
		data_malloc_error_parse(s, __func__, true, NULL);
	if (nb_arg(arr) != 1)
	{
		free_nt_arr(arr);
		return (error_generic_rt(s->p, ERR_RT_FORMAT_DOUBLE, __func__));
	}
	*data = ft_strtod(str, &end);
	if (str == end)
	{
		free_nt_arr(arr);
		return (error_generic_rt(s->p, ERR_RT_VOID_DOUBLE, __func__));
	}
	if (*end && !ft_isspace(*end))
	{
		free_nt_arr(arr);
		return (error_generic_rt(s->p, ERR_RT_INCORECT_DOUBLE, __func__));
	}
	free_nt_arr(arr);
	return (false);
}

static bool	check_brightness(t_data *s, char *str, char *end, double brght)
{
	if (str == end)
		return (error_generic_rt(s->p, ERR_RT_VOID_BRIGHTNESS, __func__));
	if (*end && !ft_isspace(*end))
		return (error_generic_rt(s->p, ERR_RT_INVALID_BRIGHTNESS, __func__));
	if (brght < 0.0 || brght > 1)
		return (error_generic_rt(s->p, ERR_RT_INCORECT_BRIGHTNESS, __func__));
	return (false);
}

bool	valid_brightness(t_data *s, char *str)
{
	char	**brightness;
	char	*end;
	double	brgh;

	brightness = ft_split(str, SEP);
	if (!brightness)
		data_malloc_error_parse(s, __func__, true, NULL);
	if (nb_arg(brightness) != 1)
	{
		free_nt_arr(brightness);
		return (error_generic_rt(s->p, ERR_RT_FORMAT_BRIGHTNESS, __func__));
	}
	brgh = ft_strtod(str, &end);
	if (check_brightness(s, str, end, brgh))
	{
		free_nt_arr(brightness);
		return (true);
	}
	s->lights.brightness = brgh;
	free_nt_arr(brightness);
	return (false);
}
