/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:52:38 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/16 15:10:57 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	full_screen(t_data *data)
{
	if (RENS.full)
	{
		data->width = DEF_WIDTH;
		data->height = DEF_HEIGHT;
		free(data->img_c);
		init_img_c(data);
		fill_control(data);
		RENS.full = false;
	}
	else
	{
		data->width = POS_X * 2;
		data->height = POS_Y * 2;
		free(data->img_c);
		init_img_c(data);
		fill_control(data);
		RENS.full = true;
	}
	mlx_set_window_fullscreen(data->mlx->mlx, data->mlx->win, RENS.full);
	render(data);
}

void	ctrl_manage(t_data *data)
{
	RENS.ctrl = !RENS.ctrl;
	render(data);
}

void	central_keyup(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == K_SPACE && RENS.space)
		RENS.space = false;
}

static void	extend_keypress(t_data *data, int key)
{
	if (RENS.ctrl && (key == K_KP_1 || key == K_KP_2))
		select_data(data, key);
	else if (RENS.ctrl
		&& (RENS.radius || RENS.diameter || RENS.height)
		&& (key == K_MINUS || key == K_KP_MINUS
			|| key == K_KP_PLUS))
		key_touch_objs_data(data, key);
	else if (RENS.ctrl
		&& !RENS.radius && !RENS.diameter && !RENS.height
		&& (key == K_MINUS || key == K_KP_MINUS || key == K_KP_PLUS))
		select_objs(data, key);
}

static void	print_sphere(t_sphere sphere)//tmp
{
	printf("%s-----%sSTRUCT_SPHERE%s-----%s\n", D_RED, ORANGE, D_RED, RESET);
	printf(ORANGE"coord_x = %f"RESET"\n", sphere.coordinate.x);
	printf(ORANGE"coord_y = %f"RESET"\n", sphere.coordinate.y);
	printf(ORANGE"coord_z = %f"RESET"\n", sphere.coordinate.z);
	printf(ORANGE"radius = %f"RESET"\n", sphere.radius);
	printf(ORANGE"red = %d"RESET"\n", sphere.color.r);
	printf(ORANGE"green = %d"RESET"\n", sphere.color.g);
	printf(ORANGE"blue = %d"RESET"\n", sphere.color.b);
}

static void	print_plane(t_plane plane)//tmp
{
	printf("%s-----%sSTRUCT_PLANE%s-----%s\n", D_RED, ORANGE, D_RED, RESET);
	printf(ORANGE"coord_x = %f"RESET"\n", plane.coordinate.x);
	printf(ORANGE"coord_y = %f"RESET"\n", plane.coordinate.y);
	printf(ORANGE"coord_z = %f"RESET"\n", plane.coordinate.z);
	printf(ORANGE"normal_x = %f"RESET"\n", plane.normal.x);
	printf(ORANGE"normal_y = %f"RESET"\n", plane.normal.y);
	printf(ORANGE"normal_z = %f"RESET"\n", plane.normal.z);
	printf(ORANGE"red = %d"RESET"\n", plane.color.r);
	printf(ORANGE"green = %d"RESET"\n", plane.color.g);
	printf(ORANGE"blue = %d"RESET"\n", plane.color.b);
}

static void	print_cylinder(t_cylinder cylinder)//tmp
{
	printf("%s-----%sSTRUCT_CYLINDER%s-----%s\n", D_RED, ORANGE, D_RED, RESET);
	printf(ORANGE"coord_x = %f"RESET"\n", cylinder.coordinate.x);
	printf(ORANGE"coord_y = %f"RESET"\n", cylinder.coordinate.y);
	printf(ORANGE"coord_z = %f"RESET"\n", cylinder.coordinate.z);
	printf(ORANGE"normal_x = %f"RESET"\n", cylinder.normal.x);
	printf(ORANGE"normal_y = %f"RESET"\n", cylinder.normal.y);
	printf(ORANGE"normal_z = %f"RESET"\n", cylinder.normal.z);
	printf(ORANGE"diameter = %f"RESET"\n", cylinder.diameter);
	printf(ORANGE"height = %f"RESET"\n", cylinder.height);
	printf(ORANGE"red = %d"RESET"\n", cylinder.color.r);
	printf(ORANGE"green = %d"RESET"\n", cylinder.color.g);
	printf(ORANGE"blue = %d"RESET"\n", cylinder.color.b);
}

static void	print_param(t_data *scene)//tmp
{
	printf("%s===========%sSCENE_PARAM%s==========%s\n", \
D_RED, MAG, D_RED, RESET);
	printf("%s-----%sAMBIANT%s-----%s\n", D_RED, ORANGE, D_RED, RESET);
	printf(ORANGE"ratio = %f"RESET"\n", scene->ambient.brightness);
	printf(ORANGE"red = %d"RESET"\n", scene->ambient.color.r);
	printf(ORANGE"green = %d"RESET"\n", scene->ambient.color.g);
	printf(ORANGE"blue = %d"RESET"\n", scene->ambient.color.b);
	printf("%s-----%sCAMERA%s-----%s\n", D_RED, ORANGE, D_RED, RESET);
	printf(ORANGE"coord_x = %f"RESET"\n", scene->camera.coordinate.x);
	printf(ORANGE"coord_y = %f"RESET"\n", scene->camera.coordinate.y);
	printf(ORANGE"coord_z = %f"RESET"\n", scene->camera.coordinate.z);
	printf(ORANGE"orient_x = %f"RESET"\n", scene->camera.orient_vector.x);
	printf(ORANGE"orient_y = %f"RESET"\n", scene->camera.orient_vector.y);
	printf(ORANGE"orient_z = %f"RESET"\n", scene->camera.orient_vector.z);
	printf(ORANGE"fov = %d"RESET"\n", scene->camera.fov);
	printf("%s-----%sLIGHT%s-----%s\n", D_RED, ORANGE, D_RED, RESET);
	printf(ORANGE"coord_x = %f"RESET"\n", scene->lights.coordinate.x);
	printf(ORANGE"coord_y = %f"RESET"\n", scene->lights.coordinate.y);
	printf(ORANGE"coord_z = %f"RESET"\n", scene->lights.coordinate.z);
	printf(ORANGE"brightness = %f"RESET"\n", scene->lights.brightness);
	printf(ORANGE"red = %d"RESET"\n", scene->lights.color.r);
	printf(ORANGE"green = %d"RESET"\n", scene->lights.color.g);
	printf(ORANGE"blue = %d"RESET"\n", scene->lights.color.b);
}

static void	print_struct(t_data *data)//tmp
{
	void	**array;
	int64_t	index;

	if (!data || !data->objs)
	{
		printf("%s===========%sNO_STRUCT_TO_PRINT%s==========%s\n", \
D_RED, MAG, D_RED, RESET);
		return ;
	}
	array = (void **)data->objs;
	index = -1;
	printf("%s===========%sSTRUCT_DATA%s==========%s\n", \
D_RED, MAG, D_RED, RESET);
	while (array[++index])
	{
		if (((t_plane *)array[index])->type == OBJ_SPHERE)
			print_sphere(*(t_sphere *)array[index]);
		else if (((t_plane *)array[index])->type == OBJ_PLANE)
			print_plane(*(t_plane *)array[index]);
		else if (((t_plane *)array[index])->type == OBJ_CYLINDER)
			print_cylinder(*(t_cylinder *)array[index]);
		else
			printf("%s===========%sSTRUCT_UNKNOWN%s==========%s\n", \
D_RED, MAG, D_RED, RESET);
	}
}

static void	key_print(t_data *data, int key)//tmp
{
	if (key == K_KP_1)
		print_param(data);
	if (key == K_KP_2)
		print_struct(data);
	printf(ORANGE"KEY_PRINT"RESET"\n");
}

void	central_keypress(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == K_ESCAPE)
		mlx_loop_end(data->mlx->mlx);
	else if (key == K_LCTRL)
		ctrl_manage(data);
	else if (!RENS.space && !RENS.ctrl && key == K_SPACE)
		RENS.space = true;
	else if (!RENS.ctrl && is_rotate(key))
		rotate(data, key);
	else if (!RENS.ctrl && (key == K_MINUS || key == K_KP_MINUS
			|| key == K_KP_PLUS))
		zoom(data, key);
	else if (key == K_F)
		full_screen(data);
	else if (!RENS.ctrl && (key == K_KP_0 || key == K_R))
		reset_sim(data);
	else if (!RENS.ctrl && is_k_arrow(key))
		arrow_move(data, key);
	else if (!RENS.ctrl && (key == K_KP_DIVIDE || key == K_KP_MULTIPLY))
		z_scale(data, key);
	else if (key == K_KP_1 || key == K_KP_2)//tmp
		key_print(data, key);
	else
		extend_keypress(data, key);
}
