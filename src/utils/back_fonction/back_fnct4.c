/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_fnct4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:11:01 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/13 13:45:33 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_sign(const char *line, int *index)
{
	int	sign;

	sign = 1;
	while (line[*index] == '+' || line[*index] == '-')
	{
		if (line[*index] == '-')
			sign *= -1;
		(*index)++;
	}
	return (sign);
}

void	reset_img(mlx_context mlx, mlx_image img, int64_t width, int64_t height)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (++j < width)
		{
			mlx_set_image_pixel(mlx, img, j, i, (mlx_color){.rgba = RGBA_NULL});
			j++;
		}
		i++;
	}
}

char	*objs_str(void **objs, int32_t index)
{
	if (OBJECT->type == OBJ_PLANE)
		return ("Plane    :");
	else if (OBJECT->type == OBJ_SPHERE)
		return ("Sphere   :");
	else if (OBJECT->type == OBJ_CYLINDER)
		return ("Cylinder :");
	else
		return ("Uknown object : ");
}

bool	is_k_arrow(int64_t key)
{
	return (key == K_RIGHT || key == K_LEFT || key == K_UP
		|| key == K_DOWN || key == K_KP_4 || key == K_KP_5
		|| key == K_KP_6 || key == K_KP_8);
}

bool	is_rotate(int64_t key)
{
	return ((key == K_W || key == K_S || key == K_A
			|| key == K_D || key == K_Q || key == K_E));
}
