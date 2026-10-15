/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:59:48 by toespino          #+#    #+#             */
/*   Updated: 2026/10/15 18:59:11 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	process_pixel(t_vector ray, int32_t index,
		t_data *s, t_color *pixel)
{
	void	**objs;

	objs = (void **)s->objs;
	if (((t_plane *)objs[index])->type == OBJ_SPHERE)
		return (render_sphere(ray, index, s, pixel));
	else if (((t_plane *)objs[index])->type == OBJ_CYLINDER)
		return (render_cylinder(ray, index, s, pixel));
	else if (((t_plane *)objs[index])->type == OBJ_PLANE)
		return (render_plane(ray, index, s, pixel));
	return (false);
}

static bool	calculate_pixel(int32_t x, int32_t y, t_color *pixel, t_data *s)
{
	t_vector	ray;
	int32_t		to_render;

	ray = generate_ray(x, y, s);
	vector_normalize(&ray);
	to_render = get_ray_target(ray, s, -1, -1);
	if (to_render == -1)
	{
		*pixel = (t_color){0};
		return (true);
	}
	if (!process_pixel(ray, to_render, s, pixel))
		return (false);
	return (true);
}

bool	render(t_data *s, int32_t i, int32_t j)
{
	t_color     *img;

	img = ft_calloc(s->height * s->width + 1, sizeof(t_color));
	if (!img)
		data_malloc_error(s, ERR_MALOC, __func__);
	while (++i < s->height)
	{
		j = -1;
		while (++j < s->width)
			if (!calculate_pixel(i, j, &img[(i + 1) * j], s))//( j, i, &img[i * s->width + j], s)?
				return (error_generic_img(ERR_PLACEHOLDER, NULL, img, true));
	}
	//s->mlx_st->img = generate_img(img, s->height, s->width);//tant que generate nes pas fait
	
	// if (!s->mlx_st || !s->mlx_st->mlx)//
	// {
	// 	free(img);
	// 	data_malloc_error(s, "mlx a fait de la merde, ou ces moi?", __func__ );//
	// }
	// s->mlx_st->img = mlx_new_image(s->mlx_st->mlx, s->height, s->width);//
	// if (!s->mlx_st->img)//
	// 	return (error_generic_img(ERR_REN_GEN_IMG, __func__, img, true));//
	
	// if (s->to_img) // a voire apres manda
	// 	mlx_save_image_to_file(mlx_st.mlx, mlx_st.img, s->to_img);
	// else
	
	//mlx_put_image_to_window(s->mlx_st->mlx, s->mlx_st->win, s->mlx_st->img, 0, 0);
	free(img);
	//mlx_destroy_image(s->mlx_st->mlx, s->mlx_st->img);
	return (true);
}
