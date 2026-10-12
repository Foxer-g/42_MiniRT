/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:37:44 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/09 14:18:46 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_cylinder(t_data *s, char **obj)
{
	if (nb_arg(obj) != 6)
	{
		error_generic_rt(s->p, ERR_RT_INVALID_DATA, __func__);
		return ;
	}
	if (ad_data_to_objs(&s->objs, "c", PTR))
		data_malloc_error(s, __func__, true, NULL);
	if (valid_coord(s, obj[1]))
		return ;
	if (valid_vector(s, obj[2]))
		return ;
	if (valid_double(s, obj[3]))
		return ;
	if (valid_double(s, obj[4]))
		return ;
	if (valid_color(s, obj[5]))
		return ;
}

void	fill_triangle(t_data *s, char **obj)//a terminer apres la manda
{
	(void)obj;
	if (ad_data_to_objs(&s->objs, "TRIANGLE EUH OUI!", PTR))
		data_malloc_error(s, __func__, true, NULL);
}
