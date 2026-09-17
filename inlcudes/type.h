/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:38:21 by toespino          #+#    #+#             */
/*   Updated: 2026/09/17 16:55:15 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <stdint.h>
# include <stdbool.h>

typedef struct	s_coodinate
{
	double	x;
	double	y;
	double	z;
}	t_coordinate;

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct	s_color
{
	int8_t	r;
	int8_t	g;
	int8_t	b;
}	t_color;

typedef struct	s_plane
{
	char			*type;
	t_coordinate	coordinate;
	t_color			color;
	t_vector		normal;
}	t_plane;

typedef struct	s_sphere
{
	char			*type;
	t_coordinate	coordinate;
	t_color			color;
	double			radius;
}	t_sphere;

typedef struct	s_cylinder
{
	char			*type;
	t_coordinate	coordinate;
	t_color			color;
	double			diameter;
	double			height;
	t_vector		normal;
}	t_cylinder;

typedef struct	s_light
{
	t_coordinate	coordinate;
	t_color			color;
	double			brightness;
}	t_light;

typedef struct	s_amb
{
	t_color	color;
	double	brightness;
}	t_amb;

typedef struct	s_data
{
	void	*objs;
	t_light	*lights;
	t_amb	ambient;

	int32_t	fov;
	int32_t	height;
	int32_t	width;
}	t_data;

#endif
