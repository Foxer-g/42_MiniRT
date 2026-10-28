/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:06:35 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 16:12:51 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"
# include "type.h"
# include "render.h"
# include "define.h"
# include "parser.h"
# include "handle.h"

# include <float.h>
# include <math.h> 
# include <stdio.h>

// a degager a la fin

void	display_head(void *objs);
void	print_cylinder(t_cylinder cylinder);
void	print_sphere(t_sphere sphere);
void	print_plane(t_plane plane);
///////////////

//==========Generic Fonction==========//
void	*ft_init_array_back(t_elem elem);
void	*ft_realloc_back(void *ptr, uintmax_t old_size, uintmax_t new_size);
void	*ft_extend_array_back(void **arr);
void	free_nt_arr(char **tab);
void	print_param(t_data *data);
void	print_struct(t_data *data);

int		get_sign(const char *line, int *index);
int		nb_arg(char **ar);
int		leap_space(char *str);

double	ft_strtod(const char *line, char **end);
double	ft_dmax(double d1, double d2);
double	ft_dmin(double d1, double d2);

bool	ad_data_scene_objects(void **arr, void *value, t_kind type);
bool	ft_isvoid(char *line);
bool	is_k_arrow(int64_t key);
//===================================//

//====For Initialization And Free====//
t_data	*init_data(void);
t_cam	*init_camera(t_data *data, uintmax_t *i);
t_light	*init_light(t_data *data, uintmax_t *i);
t_amb	init_ambient(void **obj, uintmax_t *i);

void	init_parse(t_data *data);
void	init_m_st(t_data *data);
void	init_objs(t_data *data);
void	free_data(t_data *data);
void	free_parse(t_parse *parse, bool complete);
void	free_objs(void *objs);
void	init_ren(t_data *data);
//===================================//

//==========Error Managenment==========//
void	data_malloc_error_parse\
(t_data *data, const char *location, bool gnl, char **arr);
void	data_malloc_error\
(t_data *data, char *error, const char *location);

bool	error_perror_b(char *error, const char *loc, int type, int fd);
bool	error_generic_rt(t_parse *p, char *error_message, const char *loc);
bool	error_generic(char *error_message, const char *loc, bool operator);
//=====================================//
#endif
