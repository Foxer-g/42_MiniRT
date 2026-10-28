/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:47:17 by toespino          #+#    #+#             */
/*   Updated: 2026/10/28 10:42:35 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define VEC t_vector
//==========Renderer==========//
void	vector_normalize(VEC *vec);
void	vector_inv(VEC *vec);

double	cylinder_distance(VEC ray, t_cylinder obj);
double	vetor_norm(VEC vec);
double	vector_dot(VEC vec1, VEC vec2);
double	plane_distance(VEC ray, t_plane obj);
double	sphere_distance(VEC ray, t_sphere obj);
double	get_ratio(VEC point, t_data *scene, uint64_t index, VEC normal);

int64_t	get_ray_target(VEC ray, t_data *scene);

bool	render(t_data *scene);
bool	renderer(t_data *s);
bool	render_sphere(VEC ray, int32_t i, t_data *scene, t_color *pixel);
bool	render_cylinder(VEC ray, int32_t i, t_data *scene, t_color *pixel);
bool	render_plane(VEC ray, int32_t i, t_data *scene, t_color *pixel);
bool	generate_img(t_data *data);
bool	sphere_intersect(t_vector ray, t_sphere obj);
bool	plane_intersect(t_vector ray, t_plane obj);
bool	cylinder_intersect(t_vector ray, t_cylinder obj);

VEC		generate_ray(int32_t x, int32_t y, t_data *scene);
VEC		vector_sub(VEC vec1, VEC vec2);
VEC		vector_add(VEC vec1, VEC vec2);
VEC		vector_coordinate(VEC vec, double t);

t_color	process_color(t_color color, double ratio);
t_color	render_point(t_vector point, t_data *scene, uint64_t index, \
t_vector normal);
//============================//
#endif
