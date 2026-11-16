/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 09:39:35 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/12 17:19:04 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	view_object(t_data *data, void **objs)
{
	int32_t	index;
	char	*tmp;

	index = REN->s_index;
	RENC.level = 0;
	if (OBJECT->type == OBJ_DEFAULT)
		mlx_string_put(M->mlx, M->win, RENC.ob_w, RENC.ob_h,
			(mlx_color)RGBA_ORANGE, "Uknown object are not show");
	else if (OBJECT->type == OBJ_PLANE)
		view_plane(data, objs, RENC.ob_w, RENC.ob_h);
	else if (OBJECT->type == OBJ_SPHERE)
		view_sphere(data, objs, RENC.ob_w, RENC.ob_h);
	else if (OBJECT->type == OBJ_CYLINDER)
		view_cylinder(data, objs, RENC.ob_w, RENC.ob_h);
	mlx_string_put(M->mlx, M->win, RENC.ob_w,
		(RENC.ob_h - (++RENC.level * RENC.p_h)),
		(mlx_color)RGBA_ORANGE, objs_str(objs, REN->s_index));
	tmp = ft_itoa(REN->s_index);
	if (!tmp)
		data_malloc_error(data, ERR_MALOC, __func__);
	mlx_string_put(M->mlx, M->win, RENC.ob_w + (2 * SP),
		(RENC.ob_h - (RENC.level * RENC.p_h)),
		(mlx_color)RGBA_ORANGE, tmp);
	free(tmp);
}

void	view_info(t_data *data)
{
	char	*tmp[2];

	tmp[0] = ft_itoa(FPS);
	if (data->count > MAX_IMG)
		tmp[1] = ft_itoa(MAX_IMG);
	else
		tmp[1] = ft_itoa(data->count);
	if (!tmp[0] || !tmp[1])
	{
		free_size_arr(tmp, 2);
		data_malloc_error(data, ERR_MALOC, __func__);
	}
	mlx_string_put(M->mlx, M->win, RENC.in_w, RENC.p_h,
		(mlx_color)RGBA_ORANGE, tmp[1]);
	mlx_string_put(M->mlx, M->win, RENC.in_w - (2 * SP), RENC.p_h,
		(mlx_color)RGBA_ORANGE, "Image :");
	mlx_string_put(M->mlx, M->win, RENC.in_w, (2 * RENC.p_h),
		(mlx_color)RGBA_ORANGE, tmp[0]);
	mlx_string_put(M->mlx, M->win, (RENC.in_w - (2 * SP)), (2 * RENC.p_h),
		(mlx_color)RGBA_ORANGE, "FPS max :");
	free_size_arr(tmp, 2);
}
