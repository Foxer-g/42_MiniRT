/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:47:17 by toespino          #+#    #+#             */
/*   Updated: 2026/11/07 13:09:20 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define VECTOR t_vector
# define COLOR mlx_color
# include <math.h>
# include <float.h>

// @doc t_nc
// @kind type
// @desc Bloated uncaped color representation with number bigger than 255
// @field r: uint64_t, red color;
// @field g: uint64_t, green color;
// @field b: uint64_t, blue color;
typedef struct	s_nc
{
	uint64_t	r;
	uint64_t	g;
	uint64_t	b;
}	t_nc;

bool	render(t_data scene, t_mlx mlx);
t_color	render_point(VECTOR point, t_data scene, uint64_t index, VECTOR normal);

bool	ff_free(void *imput);
void	generate_img(t_color *img, int32_t height, int32_t width, t_mlx *mlx);
double	get_ray_target(VECTOR ray, t_data scene);
t_nc	get_color(VECTOR point, t_data scene, uint64_t index, VECTOR normal);

bool	render_sphere(VECTOR ray, int32_t i, t_data scene, t_color *pixel);
bool	sphere_intersect(VECTOR ray, t_sphere obj);
double	sphere_distance(VECTOR ray, t_sphere obj);

bool	render_cylinder(VECTOR ray, int32_t i, t_data scene, t_color *pixel);
bool	cylinder_intersect(VECTOR ray, t_cylinder obj);
double	cylinder_distance(VECTOR ray, t_cylinder obj);

bool	render_plane(VECTOR ray, int32_t i, t_data scene, t_color *pixel);
bool	plane_intersect(VECTOR ray, t_plane obj);
double	plane_distance(VECTOR ray, t_plane obj);

t_color	color_incident(t_color base, t_color to_add, double r, double bright);
t_color	color_cap(t_nc to_cap);
void	light_add(t_nc *base, t_color to_add);
COLOR	to_mlx(t_color input);

double	vetor_norm(VECTOR vec);
void	vector_inv(VECTOR *vec);
void	vector_normalize(VECTOR *vec);
VECTOR	vector_sub(VECTOR vec1, VECTOR vec2);
VECTOR	vector_add(VECTOR vec1, VECTOR vec2);
double	vector_dot(VECTOR vec1, VECTOR vec2);
VECTOR	vector_coordinate(VECTOR vec, double t);
#endif
