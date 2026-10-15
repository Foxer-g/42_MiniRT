/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 18:11:32 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/14 18:12:50 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_generic_rt(t_parse *p, char *error_message, const char *loc)
{
	ft_putstr_fd(D_RED "Error\n" ORANGE, 2);
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd(Z_BLUE, 2);
	ft_putstr_fd(loc, 2);
	ft_putstr_fd(RESET"\n", 2);
	p->error = true;
	return (true);
}

bool	error_generic_img(char *error_message, const char *loc, \
t_color *img, bool operator)
{
	if (img)
		free(img);
	if (error_message && loc)
	{
		ft_putstr_fd(D_RED "[Error] " ORANGE, 2);
		ft_putstr_fd(error_message, 2);
		ft_putstr_fd(Z_BLUE, 2);
		ft_putstr_fd(loc, 2);
		ft_putstr_fd(RESET"\n", 2);
	}
	return (operator);
}
