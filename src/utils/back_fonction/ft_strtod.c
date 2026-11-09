/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 13:24:22 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/08 16:08:05 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	get_deci(const char *line, int *i, int *decimal, double *mantis)
{
	(*i)++;
	while (ft_isdigit(line[*i]))
	{
		*mantis = *mantis * 10.0 + (line[*i] - '0');
		(*decimal)++;
		(*i)++;
	}
}

static int	get_expo(const char *line, int *i, int *expo)
{
	int		sign;
	int		value;
	int		start;

	start = *i;
	(*i)++;
	sign = 1;
	if (line[*i] == '+' || line[*i] == '-')
	{
		if (line[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	if (!ft_isdigit(line[*i]))
	{
		*i = start;
		return (0);
	}
	value = 0;
	while (ft_isdigit(line[*i]))
		value = value * 10 + (line[(*i)++] - '0');
	*expo = sign * value;
	return (1);
}

static void	get_conv(double *mantis, int decimal, int expo)
{
	while (decimal > 0)
	{
		*mantis /= 10.0;
		decimal--;
	}
	if (expo >= 0)
	{
		while (expo > 0)
		{
			*mantis *= 10.0;
			expo--;
		}
	}
	else
	{
		while (expo < 0)
		{
			*mantis /= 10.0;
			expo++;
		}
	}
}

static t_strtod	init_strtod(const char *line)
{
	t_strtod	st;

	st.start = line;
	st.i = leap_space((char *)line);
	st.sign = get_sign(line, &st.i);
	st.mantis = 0.0;
	st.decimal = 0;
	st.expo = 0;
	st.end = line + st.i;
	return (st);
}

double	ft_strtod(const char *line, char **end)
{
	t_strtod	st;

	st = init_strtod(line);
	while (ft_isdigit(line[st.i]))
		st.mantis = st.mantis * 10.0 + (line[st.i++] - '0');
	if (line[st.i] == LOCAL)
		get_deci(line, &st.i, &st.decimal, &st.mantis);
	if (line[st.i] == 'e' || line[st.i] == 'E')
		get_expo(line, &st.i, &st.expo);
	*end = (char *)line + st.i;
	get_conv(&st.mantis, st.decimal, st.expo);
	if (line[st.i] == '\0' && st.mantis == 0.0)
		(void)st.start;
	return (st.mantis * st.sign);
}
