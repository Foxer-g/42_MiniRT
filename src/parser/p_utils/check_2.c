/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:08:09 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/14 17:44:10 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	check_double(t_data *s, char *str, char *end)
{
	if (str == end)
		return (error_generic_rt(s->p, ERR_RT_VOID_DOUBLE, __func__));
	if (*end && !ft_isspace(*end))
		return (error_generic_rt(s->p, ERR_RT_INCORECT_DOUBLE, __func__));
	return (false);
}

bool	valid_double(t_data *s, char *str)
{
	char	**data;
	char	*end;
	double	valid;

	data = ft_split(str, SEP);
	if (!data)
		data_malloc_error_parse(s, __func__, true, NULL);
	if (nb_arg(data) != 1)
	{
		free_nt_arr(data);
		return (error_generic_rt(s->p, ERR_RT_FORMAT_DOUBLE, __func__));
	}
	valid = ft_strtod(str, &end);
	if (check_double(s, str, end))
	{
		free_nt_arr(data);
		return (true);
	}
	if (ad_data_to_objs(&s->objs, &data, DOUBLE, 0))
		data_malloc_error_parse(s, __func__, true, data);
	free_nt_arr(data);
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
	if (ad_data_to_objs(&s->objs, &brgh, DOUBLE, 0))
		data_malloc_error_parse(s, __func__, true, brightness);
	free_nt_arr(brightness);
	return (false);
}
