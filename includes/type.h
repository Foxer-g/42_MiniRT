/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:38:21 by toespino          #+#    #+#             */
/*   Updated: 2026/09/21 17:48:35 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <stdint.h>
# include <stdbool.h>

// @doc t_coordinate
// @kind type
// @desc Representation of coordinates in space.
// @field x: double, Position on x axis.
// @field y: double, Position on y axis.
// @field z: double, Position on z axis.
typedef struct s_coodinate
{
	double	x;
	double	y;
	double	z;
}	t_coordinate;

// @doc t_vector
// @kind type
// @desc Representation of a vector in space.
// @field x: double, Vector value on x axis.
// @field y: double, Vector value on y axis.
// @field z: double, Vector value on z axis.
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

// @doc t_color
// @kind type
// @desc Representation of an RGB color.
// @field r: int8_t, Red value up to 255.
// @field g: int8_t, Green value up to 255.
// @field b: int8_t, Blue value up to 255.
typedef struct s_color
{
	int8_t	r;
	int8_t	g;
	int8_t	b;
}	t_color;

// @doc t_plane
// @kind type
// @desc Plane representation in an environement.
// @field type: char *, Object indentification field.
// @field coordinate: [[t_coordinate]], Coordinates of a point in the plane.
// @field color: [[t_color]], Plane color.
// @field normal: [[t_vector]], Plane normal vector.
typedef struct s_plane
{
	char			*type;
	t_coordinate	coordinate;
	t_color			color;
	t_vector		normal;
}	t_plane;

// @doc t_sphere
// @kind type
// @desc Sphere representation in an environement.
// @field type: char *, Object indentification field.
// @field coordinate: [[t_coordinate]], Sphere center coordinates.
// @field color: [[t_color]], Sphere color.
// @field radius: double, Sphere radius.
typedef struct s_sphere
{
	char			*type;
	t_coordinate	coordinate;
	t_color			color;
	double			radius;
}	t_sphere;

// @doc t_cylinder
// @kind type
// @desc Cylinder representation in an environement.
// @field type: char *, Object indentification field.
// @field coordinate: [[t_coordinate]], Cylinder center coordinates.
// @field color: [[t_color]], Cylinder color.
// @field diameter: double, Cylinder diameter.
// @field height: double, Cylinder height.
// @field normal: [[t_vector]], Cylinder normal vector.
typedef struct s_cylinder
{
	char			*type;
	t_coordinate	coordinate;
	t_color			color;
	double			diameter;
	double			height;
	t_vector		normal;
}	t_cylinder;

// @doc t_light
// @kind type
// @desc Sketchy light representation.
// @field coordinate: [[t_coordinate]], Light coordinates.
// @field color: [[t_color]], Light color.
// @field brightness: double, Light brightness.
typedef struct s_light
{
	t_coordinate	coordinate;
	t_color			color;
	double			brightness;
}	t_light;

// @doc t_amb
// @kind type
// @desc Sketchy ambient light representation.
// @field color: [[t_color]], Ambient light color.
// @field brightness: double, Ambient light brightness.
typedef struct s_amb
{
	t_color	color;
	double	brightness;
}	t_amb;

// @doc t_data
// @kind type
// @desc Scene representation in a struct, isn't it beatiful ?
// @field objs: void *, Scene objects array.
// @field lights: [[t_light]] *, Scene lights array.
// @field ambient: [[t_amb]], Ambient light specifications.
// @field fov: int32_t, Fov value for the camera in degres.
// @field height: int32_t, Window height in pixels.
// @field width: int32_t, Window width in pixels.
typedef struct s_data
{
	void	*objs;
	t_light	*lights;
	t_amb	ambient;

	int32_t	fov;
	int32_t	height;
	int32_t	width;
}	t_data;

#endif
