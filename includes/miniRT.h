/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:06:35 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/12 10:37:19 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"
# include "type.h"
# include "define.h"
# include <stdio.h>

// a degager
void	get_display(char **arr);
void	print_value(void *value, t_type type);

//==========Generic Fonction==========//
void	*ft_init_array_back(t_elem elem);
void	*ft_realloc_back(void *ptr, uintmax_t old_size, uintmax_t new_size);
void	*ft_extend_array_back(void **arr);
void	free_nt_arr(char **tab);

int		get_sign(const char *line, int *index);
int		nb_arg(char **ar);
int		leap_space(char *str);

double	ft_strtod(const char *line, char **end);

bool	ad_data_to_objs(void **arr, void *value, t_type type);
bool	ft_isvoid(char *line);
//===================================//

//====For Initialization And Free====//
t_data	*init_data(void);
t_parse	*init_parse(t_data *data);
t_light	*init_light(t_data *data);
t_coord	init_coordinate(void);
t_amb	init_ambient(void);
t_color	init_color(void);

void	*init_objs(t_data *data);
void	free_data(t_data *data);
void	free_parse(t_parse *parse, bool complete);
void	free_light(t_light *light);
//===================================//

//==========Error Managenment==========//
void	data_malloc_error\
(t_data *data, const char *location, bool gnl, char **arr);

int		malloc_error(int exit_code, int fd);

bool	error_perror_b(char *error, const char *loc, int type, size_t fd);
bool	error_generic_rt(t_parse *p, char *error_message, const char *loc);
//=====================================//

//==========Renderer==========//
void	render(void);
//============================//

//==========Parsing==========//
void	fill_ambient_lighting(t_data *s, t_parse *p, char **obj);
void	fill_cylinder(t_data *s, char **obj);
void	fill_triangle(t_data *s, char **obj);// a faire apres manda
void	fill_camera(t_data *s, char **obj);
void	fill_light(t_data *s, t_parse *p, char **obj);
void	fill_sphere(t_data *s, char **obj);
void	fill_plane(t_data *s, char **obj);

bool	check_line(t_data *s);
bool	check_scene(t_data *s);
bool	central_verif(t_data *scene, char **av);
bool	check_filename(const char *filename);
bool	valid_color(t_data *s, char *str);
bool	valid_ratio(t_data *s, char *str);
bool	valid_coord(t_data *s, char *str);
bool	valid_vector(t_data *s, char *str);
bool	valid_fov(t_data *s, char *str);
bool	valid_brightness(t_data *s, char *str);
bool	valid_double(t_data *s, char *str);
//===========================//

#endif
