/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:59:48 by toespino          #+#    #+#             */
/*   Updated: 2026/10/28 10:12:26 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	render_point(t_vector point, t_data *scene, uint64_t index,
		t_vector normal)
{
	double		ratio;
	t_color		res;

	ratio = ft_dmin(get_ratio(point, scene, index, normal), 1.0);
	res = process_color(((t_plane *)scene->objs)[index].color, ratio);
	return (res);
}

static bool	process_pixel(t_vector point, int32_t index,
		t_data *s, t_color *pixel)
{
	void	**objs;

	objs = (void **)s->objs;
	if (((t_plane *)objs[index])->type == OBJ_SPHERE)
		return (render_sphere(point, index, s, pixel));
	else if (((t_plane *)objs[index])->type == OBJ_CYLINDER)
		return (render_cylinder(point, index, s, pixel));
	else if (((t_plane *)objs[index])->type == OBJ_PLANE)
		return (render_plane(point, index, s, pixel));
	return (false);
}

static bool	calculate_pixel(int32_t x, int32_t y, t_color *pixel, t_data *s)
{
	t_vector	point;
	double		to_render;

	point = generate_ray(x, y, s);
	vector_normalize(&point);
	to_render = get_ray_target(point, s);
	if (to_render == -1)
	{
		*pixel = (t_color){0};
		return (true);
	}
	point = vector_coordinate(point, to_render);
	if (!process_pixel(point, to_render, s, pixel))
		return (false);
	return (true);
}

bool	renderer(t_data *s)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < s->height)
	{
		j = 0;
		while (j < s->width)
		{
			//( j, i, &img[i * s->width + j], s)?
			if (!calculate_pixel(i, j, &s->img_c[(i + 1) * j], s))
				return (error_generic(ERR_PLACEHOLDER, NULL, true));
			j++;
		}
		i++;
	}
	if (generate_img(s))
		return (true);
	return (false);
}

// if (s->to_img) // a voire apres manda et a mettre dans generate_img
	// 	mlx_save_image_to_file(m_st.mlx, m_st.img, s->to_img);
	// mlx_add_loop_hook(s->m_st->mlx, central_keypress, s);

bool	render(t_data *s)
{
	init_m_st(s);
	s->img_c = ft_calloc(s->height * s->width + 1, sizeof(t_color));
	if (!s->img_c)
		data_malloc_error(s, ERR_MALOC, __func__);
	mlx_option(s);
	get_hook (s);
	if (renderer(s))
		return (true);
	mlx_loop(s->m_st->mlx);
	return (false);
}
