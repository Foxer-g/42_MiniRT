/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:47:17 by toespino          #+#    #+#             */
/*   Updated: 2026/10/20 04:20:14 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define VEC t_vector
bool	render(t_data scene, t_mlx mlx);
int64_t	get_ray_target(VEC ray, t_data scene);
VEC		generate_ray(int32_t x, int32_t y, t_data scene);

bool	render_sphere(VEC ray, int32_t i, t_data scene, t_color *pixel);
double	sphere_distance(VEC ray, t_sphere obj);

bool	render_cylinder(VEC ray, int32_t i, t_data scene, t_color *pixel);
double	cylinder_distance(VEC ray, t_cylinder obj);

bool	render_plane(VEC ray, int32_t i, t_data scene, t_color *pixel);
double	plane_distance(VEC ray, t_plane obj);

double	vetor_norm(VEC vec);
void	vector_inv(t_vector *vec);
void	vector_normalize(VEC *vec);
VEC		vector_sub(VEC vec1, VEC vec2);
VEC		vector_add(VEC vec1, VEC vec2);
double	vector_dot(VEC vec1, VEC vec2);
t_coord	vector_coordinate(t_vector vec, double t);
#endif
