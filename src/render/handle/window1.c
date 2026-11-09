/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:40:03 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/09 17:05:17 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	central_window(int key, void *param)
{
	t_data	*data;
	t_mlx	*m;

	data = (t_data *)param;
	m = data->mlx;
	if (key == K_CROSS)
		mlx_loop_end(m->mlx);
}
