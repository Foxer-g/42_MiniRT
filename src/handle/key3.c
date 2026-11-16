/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:58:45 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/16 09:48:23 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	key_touch_objs_data(t_data *data, int key)
{
	void	**objs;
	double	add;

	add = ADD;
	if (key == K_MINUS || key == K_KP_MINUS)
		add = -add;
	objs = (void **)data->objs;
	if (((t_plane *)objs[data->ren->s_index])->type == OBJ_SPHERE
		&& !data->ren->stor.height && !data->ren->stor.diameter)
		((t_sphere *)objs[data->ren->s_index])->radius += add;
	else if (((t_plane *)objs[data->ren->s_index])->type == OBJ_CYLINDER)
	{
		if (!data->ren->stor.radius && !data->ren->stor.diameter)
			((t_cylinder *)objs[data->ren->s_index])->height += add;
		else if (!data->ren->stor.radius && !data->ren->stor.height)
			((t_cylinder *)objs[data->ren->s_index])->diameter += add;
	}
	render(data);
}

void	reset_sim(t_data *data)
{
	REN->offset_x = 0;
	REN->offset_y = 0;
	REN->alpha = DEFAULT_ALPHA;
	REN->beta = DEFAULT_BETA;
	REN->gamma = 0;
	REN->scale = 1;
	REN->z_scale = 1;
	render(data);
}
