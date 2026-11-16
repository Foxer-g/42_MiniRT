/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:47:17 by toespino          #+#    #+#             */
/*   Updated: 2026/11/16 11:06:48 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define OBJ ((t_plane *)scene->objs)[index]
# define OBJECT ((t_plane *)objs[index])
# define LIGHT scene->lights
# define M (data->mlx)

# define VEC t_vector
# define COLOR mlx_color

bool	render(t_data *scene);
COLOR	render_point(VEC point, t_data *scene, uint64_t index, VEC normal);

bool	ff_free(void *input);
void	create_img(t_data *scene);
int64_t	get_ray_target(VEC ray, t_data *scene, double *distance);
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
