/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:59:48 by toespino          #+#    #+#             */
/*   Updated: 2026/09/22 16:29:00 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	process_pixel(t_vector ray, int32_t index, t_data scene,
		t_color *pixel)
{
	if (((t_plane) scene.objs[index].type == s))
		return (render_sphere());
	else if (((t_plane) scene.objs[index].type == c))
		return (render_cylinder());
	else if (((t_plane) scene.objs[index].type == p))
		return (render_plane());
	else
		return (false);
}
static bool	calculate_pixel(int32_t x, int32_t y, t_color *pixel, t_data scene)
{
	t_vector	ray;
	int32_t		to_render;

	ray = generate__ray(x, y);
	to_render = get_ray_target(ray, scene);
	if (to_render == -1)
	{
		*pixel.r = 0;
		*pixel.g = 0;
		*pixel.b = 0;
		return (true);
	}
	if (!process_pixel(ray, to_render, scene))
		return (false);
	return (true);
}

bool	render(t_data scene, t_mlx mlx)
{
	t_color	*img;

	img = ft_calloc(scene.height * scene.width + 1, sizeof(t_color));
	if (!img)
		return (error_message(MALLOC));
	i = -1;
	while (++i < scene.height)
	{
		j = -1;
		while (++j < scene.width)
		{
			if (!calculate_pixel(i, j, &img[(i + 1) * j], scene))
			{
				free(img);
				return (false);
			}
		}
	}
}
