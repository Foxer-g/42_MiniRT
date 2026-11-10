/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:47:17 by toespino          #+#    #+#             */
/*   Updated: 2026/11/10 15:28:12 by toespino         ###   ########.fr       */
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
mlx_color	render_point(VEC point, t_data *scene, uint64_t index, VEC normal);

bool	ff_free(void *imput);
void	create_img(t_data *scene);
int64_t get_ray_target(VEC ray, t_data *scene);
t_nc	gemlx_color(VEC point, t_data *scene, uint64_t index, VEC normal);

bool	render_sphere(VEC ray, int32_t i, t_data *scene, mlx_color *pixel);
bool	sphere_intersect(VEC ray, t_sphere obj);
double	sphere_distance(VEC ray, t_sphere obj);

bool	render_cylinder(VEC ray, int32_t i, t_data *scene, mlx_color *pixel);
bool	cylinder_intersect(VEC ray, t_cylinder obj);
double	cylinder_distance(VEC ray, t_cylinder obj);

bool	render_plane(VEC ray, int32_t i, t_data *scene, mlx_color *pixel);
bool	plane_intersect(VEC ray, t_plane obj);
double	plane_distance(VEC ray, t_plane obj);

mlx_color	color_incident(mlx_color base, mlx_color to_add, double r, double bright);
mlx_color	color_cap(t_nc to_cap);
void	light_add(t_nc *base, mlx_color to_add);
COLOR	to_mlx(mlx_color input);

double	vector_norm(VEC vec);
void	vector_inv(VEC *vec);
void	vector_normalize(VEC *vec);
VEC		vector_sub(VEC vec1, VEC vec2);
VEC		vector_add(VEC vec1, VEC vec2);
double	vector_dot(VEC vec1, VEC vec2);
VEC		vector_coordinate(VEC vec, double t);
#endif
