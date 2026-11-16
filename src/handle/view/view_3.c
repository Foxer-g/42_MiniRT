/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:34:44 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/13 13:57:32 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	view_coordinate(t_data *data, t_vector vec, uint32_t w, uint32_t h)
{
	char		*tmp[3];

	tmp[0] = ft_dtoa(vec.x);
	tmp[1] = ft_dtoa(vec.y);
	tmp[2] = ft_dtoa(vec.z);
	if (!tmp[0] || !tmp[1] || !tmp[2])
	{
		free_size_arr(tmp, 3);
		data_malloc_error(data, ERR_MALOC, __func__);
	}
	mlx_string_put(data->mlx->mlx, data->mlx->win, w, h,
		(mlx_color)RGBA_ORANGE, tmp[2]);
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		(w + data->ren->control.sp), h,
		(mlx_color)RGBA_ORANGE, tmp[1]);
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		(w + (2 * data->ren->control.sp)), h,
		(mlx_color)RGBA_ORANGE, tmp[0]);
	mlx_string_put(data->mlx->mlx, data->mlx->win, data->ren->control.ob_w,
		(data->ren->control.ob_h
			- (++data->ren->control.level * data->ren->control.p_h)),
		(mlx_color)RGBA_ORANGE, "Coordinate :");
	free_size_arr(tmp, 3);
}

void	view_color(t_data *data, mlx_color color, uint32_t w, uint32_t h)
{
	char		*tmp[3];
	uint32_t	h_color;

	tmp[0] = ft_itoa(color.r);
	tmp[1] = ft_itoa(color.g);
	tmp[2] = ft_itoa(color.b);
	if (!tmp[0] || !tmp[1] || !tmp[2])
	{
		free_size_arr(tmp, 3);
		data_malloc_error(data, ERR_MALOC, __func__);
	}
	h_color = h + (++data->ren->control.level * -data->ren->control.p_h);
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		data->ren->control.ob_w, h_color,
		(mlx_color)RGBA_ORANGE, tmp[2]);
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		(w + data->ren->control.sp), h_color,
		(mlx_color)RGBA_ORANGE, tmp[1]);
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		(w + (2 * data->ren->control.sp)), h_color,
		(mlx_color)RGBA_ORANGE, tmp[0]);
	mlx_string_put(data->mlx->mlx, data->mlx->win, w,
		(h - (++data->ren->control.level * data->ren->control.p_h)),
		(mlx_color)RGBA_ORANGE, "Color RGB :");
	free_size_arr(tmp, 3);
}

void	view_normal(t_data *data, t_vector vec, uint32_t w, uint32_t h)
{
	uint32_t	h_normal;
	char		*tmp[3];

	tmp[0] = ft_dtoa(vec.x);
	tmp[1] = ft_dtoa(vec.y);
	tmp[2] = ft_dtoa(vec.z);
	if (!tmp[0] || !tmp[1] || !tmp[2])
	{
		free_size_arr(tmp, 3);
		data_malloc_error(data, ERR_MALOC, __func__);
	}
	h_normal = h + (++data->ren->control.level * -data->ren->control.p_h);
	mlx_string_put(data->mlx->mlx, data->mlx->win, w, h_normal,
		(mlx_color)RGBA_ORANGE, tmp[2]);
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		(w + data->ren->control.sp), h_normal,
		(mlx_color)RGBA_ORANGE, tmp[1]);
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		(w + (2 * data->ren->control.sp)), h_normal,
		(mlx_color)RGBA_ORANGE, tmp[0]);
	mlx_string_put(data->mlx->mlx, data->mlx->win, w,
		(h - (++data->ren->control.level * data->ren->control.p_h)),
		(mlx_color)RGBA_ORANGE, "Vector Normal :");
	free_size_arr(tmp, 3);
}

void	view_double_value(t_data *data, char *msg, uint32_t w, uint32_t h)
{
	char		*tmp;
	uint32_t	h_doule;

	tmp = ft_dtoa(data->ren->control.d_value);
	if (!tmp)
		data_malloc_error(data, ERR_MALOC, __func__);
	h_doule = h + (++data->ren->control.level
			* -data->ren->control.p_h);
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		data->ren->control.ob_w, h_doule,
		(mlx_color)RGBA_ORANGE, tmp);
	mlx_string_put(data->mlx->mlx, data->mlx->win, w,
		(h - (++data->ren->control.level * data->ren->control.p_h)),
		(mlx_color)RGBA_ORANGE, msg);
	free(tmp);
}

void	view_int_value(t_data *data, char *msg, uint32_t w, uint32_t h)
{
	char		*tmp;
	uint32_t	h_int;

	tmp = ft_dtoa(data->ren->control.i_value);
	if (!tmp)
		data_malloc_error(data, ERR_MALOC, __func__);
	h_int = h + (++data->ren->control.level
			* -data->ren->control.p_h);
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		data->ren->control.ob_w, h_int,
		(mlx_color)RGBA_ORANGE, tmp);
	mlx_string_put(data->mlx->mlx, data->mlx->win, w,
		(h - (++data->ren->control.level * data->ren->control.p_h)),
		(mlx_color)RGBA_ORANGE, msg);
	free(tmp);
}
