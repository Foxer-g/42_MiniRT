/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:06:35 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 19:06:44 by ethutin-         ###   ########.fr       */
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

# include <float.h>
# include <math.h> 
# include <stdio.h>

// a degager
void	get_display(char **arr);
void	print_value(void *value, t_type type);
void	print_struct(t_st_type type);

//==========Generic Fonction==========//
void	*ft_init_array_back(t_elem elem);
void	*ft_realloc_back(void *ptr, uintmax_t old_size, uintmax_t new_size);
void	*ft_extend_array_back(void **arr);
void	free_nt_arr(char **tab);

int		get_sign(const char *line, int *index);
int		nb_arg(char **ar);
int		leap_space(char *str);

double	ft_strtod(const char *line, char **end);

bool	ad_data_to_objs(void **arr, void *value, t_type type, size_t size);
bool	ad_data_scene_objs(void **arr, void *value, t_st_type type);
bool	ft_isvoid(char *line);
//===================================//

//====For Initialization And Free====//
t_data	*init_data(void);
t_parse	*init_parse(t_data *data);
//t_mlx	*init_mlx_st(t_data *data, uintmax_t i);

t_coord	init_coordinate(void **obj, uintmax_t *i);
t_color	init_color(void **obj, uintmax_t *i);
VEC		init_vector(void **obj, uintmax_t *i);

t_cam	*init_camera(t_data *data, uintmax_t *i);
t_light	*init_light(t_data *data, uintmax_t *i);
t_amb	init_ambient(void **obj, uintmax_t *i);

void	*init_objs(t_data *data);
void	*init_scene_objs(t_data *data);
void	free_data(t_data *data);
void	free_parse(t_parse *parse, bool complete);
void	free_light(t_light *light);
void	free_camera(t_cam *camera);
void	free_mlx_st(t_mlx *mlx_st);
void	init_scene(t_data *data);
//===================================//

//==========Error Managenment==========//
void	data_malloc_error_parse\
(t_data *data, const char *location, bool gnl, char **arr);
void	data_malloc_error\
(t_data *data, char *error, const char *location);

int		malloc_error(const char *loc, int exit_code, int fd);

bool	error_perror_b(char *error, const char *loc, int type, int fd);
bool	error_generic_rt(t_parse *p, char *error_message, const char *loc);
bool	error_generic_img(char *error_message, const char *loc, \
t_color *img, bool operator);
//=====================================//
#endif
