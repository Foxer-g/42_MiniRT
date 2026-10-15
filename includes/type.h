/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:38:21 by toespino          #+#    #+#             */
/*   Updated: 2026/10/15 19:05:31 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <stdint.h>
# include <stdbool.h>
# include "mlx.h"
# include "mlx_extended.h"

// @doc t_coord
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
}	t_coord;

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
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_color;

// @doc t_plane
// @kind type
// @desc Plane representation in an environement.
// @field type: char *, Object indentification field.
// @field coordinate: [[t_coord]], Coordinates of a point in the plane.
// @field color: [[t_color]], Plane color.
// @field normal: [[t_vector]], Plane normal vector.
typedef struct s_plane
{
	uint8_t			type;	
	t_coord			coordinate;
	t_color			color;
	t_vector		normal;
}	t_plane;

// @doc t_sphere
// @kind type
// @desc Sphere representation in an environement.
// @field type: char *, Object indentification field.
// @field coordinate: [[t_coord]], Sphere center coordinates.
// @field color: [[t_color]], Sphere color.
// @field radius: double, Sphere radius.
typedef struct s_sphere
{
	uint8_t			type;	
	t_coord			coordinate;
	t_color			color;
	double			radius;
}	t_sphere;

// @doc t_cylinder
// @kind type
// @desc Cylinder representation in an environement.
// @field type: char *, Object indentification field.
// @field coordinate: [[t_coord]], Cylinder center coordinates.
// @field color: [[t_color]], Cylinder color.
// @field diameter: double, Cylinder diameter.
// @field height: double, Cylinder height.
// @field normal: [[t_vector]], Cylinder normal vector.
typedef struct s_cylinder
{
	uint8_t			type;	
	t_coord			coordinate;
	t_color			color;
	double			diameter;
	double			height;
	t_vector		normal;
}	t_cylinder;

// @doc t_light
// @kind type
// @desc Sketchy light representation.
// @field coordinate: [[t_coord]], Light coordinates.
// @field color: [[t_color]], Light color.
// @field brightness: double, Light brightness.
typedef struct s_light
{
	t_coord			coordinate;
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

// @doc t_parse
// @kind type
// @field obj: char **, the decomposition of line.
// @field line: char *, line extract from the file provided.
// @field fd: int32_t, the file descriptor use to open the file provided.
// @field error: bool, identifier use in the parsing to stop the program.
// @field al: bool, identifier use in the parsing to block replication of data.
// @field c: bool, identifier use in the parsing to block replication of data.
// @field l: bool, identifier use in the parsing to block replication of data.
typedef struct s_parse
{
	char	**obj;
	char	*line;

	int32_t	fd;

	bool	error;
	bool	al;
	bool	c;
	bool	l;
}	t_parse;

// @doc t_cam
// @kind type
// @field vector: [[t_vector]], Normalized orientation vector.
// @field coordinate: [[t_coord]], Coordinates of the viewpoint.
// @field fov: int32_t, Field of view of the cmera.
typedef struct s_cam
{
	t_vector	vector;
	t_coord		coordinate;

	int32_t		fov;
}	t_cam;

// @doc t_mlx
// @kind type
// @desc Basics ressources to work with MacrolibX.
// @field mlx: mlx_content, MacrolibX data.
// @filed win: mlx_window, MacrolibX window data.
// @filed img: mlx_image, MacrolibX image data.
typedef struct s_mlx
{
	mlx_context	mlx;
	mlx_window	win;
	mlx_image	img;
}	t_mlx;

typedef enum st_type
{
	SPH,
	PLA,
	CYL
}	t_st_type;

typedef enum s_kind
{
	OBJ_PLANE,
	OBJ_SPHERE,
	OBJ_CYLINDER,
	OBJ_DEFAULT
}	t_kind;

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
	void	*scene_objs;

	t_parse	*p;
	t_light	*lights;
	t_amb	ambient;
	t_cam	*camera;
	t_mlx	*mlx_st;

	int32_t	height;
	int32_t	width;

	char	*to_img;
}	t_data;

typedef struct s_strtod
{
	const char	*start;
	const char	*end;

	int			i;
	int			sign;
	int			decimal;
	int			expo;

	double		mantis;
}	t_strtod;

#endif
