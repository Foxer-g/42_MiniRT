/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:59:48 by toespino          #+#    #+#             */
/*   Updated: 2026/10/28 11:04:15 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	render_point(t_vector point, t_data scene, uint64_t index,
		t_vector normal)
{
	t_color		res;
	t_nc		no_cap;

	no_cap = get_color(point, normal, scene, index);
	res = color_cap(no_cap);
	return (res);
}

static bool	process_pixel(t_vector point, int32_t index, t_data scene,
		t_color *pixel)
{
	if (((t_plane) scene.objs[index].type == s))
		return (render_sphere(point, index, scene, pixel));
	else if (((t_plane) scene.objs[index].type == c))
		return (render_cylinder(point, index, scene, pixel));
	else if (((t_plane) scene.objs[index].type == p))
		return (render_plane(point, index, scene, pixel));
	else
		return (false);
}

static bool	calculate_pixel(int32_t x, int32_t y, t_color *pixel, t_data scene)
{
	t_vector	ray;
	double		to_render;

	ray = generate_ray(x, y, scene);
	vector_normalize(&ray);
	to_render = get_ray_target(ray, scene);
	if (to_render == -1)
	{
		*pixel = (t_color){0};
		return (true);
	}
	point = vector_coordinate(ray, to_render);
	if (!process_pixel(point, to_render, scene, pixel))
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
