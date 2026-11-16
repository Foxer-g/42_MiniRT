/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:38:21 by toespino          #+#    #+#             */
/*   Updated: 2026/11/16 10:18:13 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <stdint.h>
# include <stdbool.h>
# include "mlx.h"
# include "mlx_extended.h"

# define COLOR mlx_color

//////////TEMPORAIRE_PEUX_CHANGER///////////

typedef struct s_control
{
	double		d_value;

	uint32_t	level;
	uint32_t	p_w;
	uint32_t	p_h;
	uint32_t	sp;
	uint32_t	ob_h;
	uint32_t	ob_w;
	uint32_t	in_h;
	uint32_t	in_w;

	int32_t		i_value;
}	t_control;

typedef struct s_bool_storage
{
	bool	radius;
	bool	height;
	bool	diameter;
	bool	space;
	bool	ctrl;
	bool	full;
}	t_bool_storage;

typedef struct s_mouse
{
	bool	l_click;
	bool	m_click;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
}	t_mouse;

typedef struct s_ren
{
	double			offset_x;
	double			offset_y;
	double			scale;
	double			z_scale;
	double			alpha;
	double			beta;
	double			gamma;

	int32_t			s_index;

	t_bool_storage	stor;
	t_mouse			mouse;
	t_control		control;
}	t_ren;

///////////////////////////////////////////////////

// @doc t_nc
// @kind type
// @desc Bloated uncaped color representation with number bigger than 255
// @field r: uint64_t, red color;
// @field g: uint64_t, green color;
// @field b: uint64_t, blue color;
typedef struct s_nc
{
	uint64_t	r;
	uint64_t	g;
	uint64_t	b;
}	t_nc;

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

// @doc t_plane
// @kind type
// @desc Plane representation in an environement.
// @field type: char *, Object indentification field.
// @field coordinate: [[t_vector]], Coordinates of a point in the plane.
// @field color: [[mlx_color]], Plane color.
// @field normal: [[t_vector]], Plane normal vector.
typedef struct s_plane
{
	uint8_t			type;	
	t_vector		coordinate;
	COLOR			color;
	t_vector		normal;
}	t_plane;

// @doc t_sphere
// @kind type
// @desc Sphere representation in an environement.
// @field type: char *, Object indentification field.
// @field coordinate: [[t_vector]], Sphere center coordinates.
// @field color: [[mlx_color]], Sphere color.
// @field radius: double, Sphere radius.
typedef struct s_sphere
{
	uint8_t			type;	
	t_vector		coordinate;
	COLOR			color;
	double			radius;
}	t_sphere;

// @doc t_cylinder
// @kind type
// @desc Cylinder representation in an environement.
// @field type: char *, Object indentification field.
// @field coordinate: [[t_vector]], Cylinder center coordinates.
// @field color: [[mlx_color]], Cylinder color.
// @field normal: [[t_vector]], Cylinder normal vector.
// @field height: double, Cylinder height.
// @field diameter: double, Cylinder diameter.
typedef struct s_cylinder
{
	uint8_t			type;	
	t_vector		coordinate;
	COLOR			color;
	t_vector		normal;

	double			height;
	double			diameter;
}	t_cylinder;

// @doc t_light
// @kind type
// @desc Sketchy light representation.
// @field coordinate: [[t_vector]], Light coordinates.
// @field color: [[mlx_color]], Light color.
// @field brightness: double, Light brightness.
typedef struct s_light
{
	t_vector		coordinate;
	COLOR			color;
	double			brightness;
}	t_light;

// @doc t_amb
// @kind type
// @desc Sketchy ambient light representation.
// @field color: [[mlx_color]], Ambient light color.
// @field brightness: double, Ambient light brightness.
typedef struct s_amb
{
	COLOR		color;
	double		brightness;
}	t_amb;

// @doc t_parse
// @kind type
// @field obj: char **, the decomposition of line.
// @field line: char *, line extract from the file provided.
// @field fd: int32_t, the file descriptor use to open the file provided.
// @field error: bool, identifier use in the parsing to stop the program.
// @field al: bool, identifier use in the parsing to block replication of data.
// @field c: bool, identifier use in the parsing to block replication of data.
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
// @field coordinate: [[t_vector]], Coordinates of the viewpoint.
// @field fov: int32_t, Field of view of the cmera.
typedef struct s_cam
{
	t_vector	orient_vector;
	t_vector	coordinate;

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
	mlx_image	c_img;
}	t_mlx;

typedef enum s_kind
{
	OBJ_DEFAULT,
	OBJ_PLANE,
	OBJ_SPHERE,
	OBJ_CYLINDER
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
	void		*objs;

	int32_t		nb_objs;
	int64_t		height;
	int64_t		width;
	int64_t		count;

	t_parse		*p;
	t_amb		ambient;
	t_cam		camera;
	t_light		lights;
	t_mlx		*mlx;
	t_ren		*ren;
	COLOR		*img_c;

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
