/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_fnct4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:43:04 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 17:04:25 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_sphere(t_sphere sphere)
{
	printf("%s-----%sSTRUCT_SPHERE%s-----%s\n", D_RED, ORANGE, D_RED, RESET);
	printf(ORANGE"coord_x = %f"RESET"\n", sphere.coordinate.x);
	printf(ORANGE"coord_y = %f"RESET"\n", sphere.coordinate.y);
	printf(ORANGE"coord_z = %f"RESET"\n", sphere.coordinate.z);
	printf(ORANGE"radieu = %f"RESET"\n", sphere.radius);
	printf(ORANGE"red = %d"RESET"\n", sphere.color.r);
	printf(ORANGE"green = %d"RESET"\n", sphere.color.g);
	printf(ORANGE"blue = %d"RESET"\n", sphere.color.b);
}

void	print_plane(t_plane plane)
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

void	print_cylinder(t_cylinder cylinder)
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

void	print_param(t_data *scene)
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

void	print_struct(t_data *data)
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
