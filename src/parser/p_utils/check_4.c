/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:10:25 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/09 15:12:16 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
		data_malloc_error(s, __func__, true, NULL);
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
	if (ad_data_to_objs(&s->objs, &ratio, DOUBLE))
		data_malloc_error(s, __func__, true, ratio);
	free_nt_arr(ratio);
	return (false);
}
