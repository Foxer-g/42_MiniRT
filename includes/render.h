/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:47:17 by toespino          #+#    #+#             */
/*   Updated: 2026/11/11 14:54:49 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define VEC t_vector
# define COLOR mlx_color

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

bool	render(t_data *scene);
COLOR	render_point(VEC point, t_data *scene, uint64_t index, VEC normal);

bool	ff_free(void *imput);
void	create_img(t_data *scene);
int64_t get_ray_target(VEC ray, t_data *scene);
t_nc	get_color(VEC point, t_data *scene, uint64_t index, VEC normal);

bool	render_sphere(VEC ray, int32_t i, t_data *scene, COLOR *pixel);
bool	sphere_intersect(VEC ray, t_sphere obj);
double	sphere_distance(VEC ray, t_sphere obj);

bool	render_cylinder(VEC ray, int32_t i, t_data *scene, COLOR *pixel);
bool	cylinder_intersect(VEC ray, t_cylinder obj);
double	cylinder_distance(VEC ray, t_cylinder obj);

bool	render_plane(VEC ray, int32_t i, t_data *scene, COLOR *pixel);
bool	plane_intersect(VEC ray, t_plane obj);
double	plane_distance(VEC ray, t_plane obj);

COLOR	color_incident(COLOR base, COLOR to_add, double r, double bright);
COLOR	color_cap(t_nc to_cap);
void	light_add(t_nc *base, COLOR to_add);

double	vector_norm(VEC vec);
void	vector_inv(VEC *vec);
void	vector_normalize(VEC *vec);
VEC		vector_sub(VEC vec1, VEC vec2);
VEC		vector_add(VEC vec1, VEC vec2);
double	vector_dot(VEC vec1, VEC vec2);
VEC		vector_coordinate(VEC vec, double t);
#endif
