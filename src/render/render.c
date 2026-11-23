/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:59:48 by toespino          #+#    #+#             */
/*   Updated: 2026/11/17 04:35:01 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vector	generate_ray(int32_t x, int32_t y, t_data *scene, VEC right)
{
	t_vector	forward;
	t_vector	up;
	t_vector	ray;
	double		fov;

	forward = scene->camera.orient_vector;
	up = vector_cross(forward, right);
	fov = tan(scene->camera.fov * M_PI / 360.0);
	ray = vector_add(forward, vector_coordinate(right,
				(2.0 * (x + 0.5) / scene->width - 1.0) * fov));
	ray = vector_add(ray, vector_coordinate(up,
				(1.0 - 2.0 * (y + 0.5) / scene->height)
				* fov * scene->height / scene->width));
	return (ray);
}

COLOR	render_point(VEC point, t_data *scene, uint64_t index, VEC normal)
{
	mlx_color	res;
	t_nc		no_cap;

	no_cap = get_color(point, scene, index, normal);
	res = color_cap(no_cap);
	return (res);
}

static bool	process_pixel(t_vector point, int64_t index,
		t_data *scene, COLOR *pixel)
{
	if (((t_plane *)scene->objs[index])->type == OBJ_SPHERE)
		return (render_sphere(point, index, scene, pixel));
	else if (((t_plane *)scene->objs[index])->type == OBJ_CYLINDER)
		return (render_cylinder(point, index, scene, pixel));
	else if (((t_plane *)scene->objs[index])->type == OBJ_PLANE)
		return (render_plane(point, index, scene, pixel));
	return (false);
}

static bool	calculate_pixel(int32_t x, int32_t y, int64_t index, t_data *scene, VEC r)
{
	t_vector	ray;
	t_vector	point;
	int64_t		to_render;
	double		distance;

	ray = generate_ray(x, y, scene, r);
	vector_normalize(&ray);
	to_render = get_ray_target(ray, scene, &distance);
	scene->img_c[index] = (mlx_color){.rgba = 0xFFFFFF};
	if (to_render == -1)
	{
		scene->img_c[index] = (mlx_color){0};
		return (true);
	}
	point = vector_coordinate(ray, distance);
	if (!process_pixel(point, to_render, scene, &(scene->img_c[index])))
		return (false);
	return (true);
}

bool	render(t_data *scn)
{
	t_vector	r;
	t_vector	up;
	int64_t		i[2];

	up = (t_vector){0, 1, 0};
	if (fabs(scn->camera.orient_vector.y) > 0.999)
		up = (t_vector){0, 0, 1};
	r = vector_cross(up, scn->camera.orient_vector);
	vector_normalize(&r);
	i[0] = -1;
	while (++i[0] < scn->height)
	{
		i[1] = -1;
		while (++i[1] < scn->width)
			if (!calculate_pixel(i[1], i[0], i[0] * scn->width + i[1], scn, r))
				return (true);
	}
	scn->mlx->img = mlx_new_image(scn->mlx->mlx,
			scn->width, scn->height);
	if (!scn->mlx->img)
		return (true);
	create_img(scn);
	mlx_put_image_to_window(scn->mlx->mlx, scn->mlx->win,
		scn->mlx->img, 0, 0);
	return (false);
}
