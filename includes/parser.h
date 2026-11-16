/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 08:24:04 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/16 10:04:29 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//==========Parsing==========//
void		fill_ambient_lighting(t_data *data, t_parse *p, char **obj);
void		fill_cylinder(t_data *data, char **obj);
void		fill_camera(t_data *data, t_parse *p, char **obj);
void		fill_light(t_data *data, t_parse *p, char **obj);
void		fill_sphere(t_data *data, char **obj);
void		fill_plane(t_data *data, char **obj);

bool		check_line(t_data *data);
bool		check_scene(t_data *data);
bool		central_verif(t_data *scene, char **av);
bool		check_filename(const char *filename, char *extension);
bool		extend_fail(t_header *header, void **arr, void *new_value);
bool		valid_ratio(t_data *data, char *str);
bool		valid_fov(t_data *data, char *str);
bool		valid_brightness(t_data *data, char *str);
bool		valid_vector(t_data *data, t_vector *vector, char *str, bool type);
bool		valid_color(t_data *data, mlx_color *color, char *str);
bool		valid_double(t_data *data, double *value, char *str);
//===========================//
#endif
