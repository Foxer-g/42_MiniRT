/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:06:35 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/16 10:49:28 by ethutin-         ###   ########.fr       */
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

//==========Generic Fonction==========//
char	*objs_str(void **objs, int32_t index);
char	*ft_utoa(uint64_t n);
char	*ft_dtoa(double n);

void	*ft_init_array_back(t_elem elem);
void	*ft_realloc_back(void *ptr, uintmax_t old_size, uintmax_t new_size);
void	*ft_extend_array_back(void **arr);
void	free_nt_arr(char **tab);
void	ft_rev(char *str, uintmax_t isnegative);
void	free_size_arr(char **tab, size_t size);
void	reset_img(mlx_context mlx, mlx_image img, \
int64_t width, int64_t height);

int32_t	get_10_pow(uint64_t value);

int		get_sign(const char *line, int *index);
int		nb_arg(char **ar);
int		leap_space(char *str);

double	ft_strtod(const char *line, char **end);

bool	ad_data_scene_objects(void **arr, void *value, t_kind type);
bool	ft_isvoid(char *line);
bool	is_k_arrow(int64_t key);
bool	is_rotate(int64_t key);
//===================================//

//====For Initialization And Free====//
t_data	*init_data(void);

void	init_parse(t_data *data);
void	init_objs(t_data *data);
void	free_data(t_data *data);
void	free_parse(t_parse *parse, bool complete);
void	init_mlx(t_data *data);
void	init_ren(t_data *data);
void	init_img_c(t_data *data);
void	fill_control(t_data *data);

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
