/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:40:03 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 16:06:40 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	central_window(int key, void *param)
{
	t_data	*data;
	t_mlx	*m;

	data = (t_data *)param;
	m = data->m_st;
	if (key == K_CROSS)
		mlx_loop_end(m->mlx);
}
