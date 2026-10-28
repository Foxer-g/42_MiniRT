/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 08:24:04 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 11:21:26 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
//==========Parsing==========//
void		fill_ambient_lighting(t_data *s, t_parse *p, char **obj);
void		fill_cylinder(t_data *s, char **obj);
// void		fill_triangle(t_data *s, char **obj);// a faire apres manda
void		fill_camera(t_data *s, t_parse *p, char **obj);
void		fill_light(t_data *s, t_parse *p, char **obj);
void		fill_sphere(t_data *s, char **obj);
void		fill_plane(t_data *s, char **obj);

bool		check_line(t_data *s);
bool		check_scene(t_data *s);
bool		central_verif(t_data *scene, char **av);
bool		check_filename(const char *filename);
bool		extend_fail(t_header *header, void **arr, void *new_value);
bool		valid_ratio(t_data *s, char *str);
bool		valid_fov(t_data *s, char *str);
bool		valid_brightness(t_data *s, char *str);
bool		valid_vector(t_data *s, t_vector *vector, char *str, bool type);
bool		valid_color(t_data *s, t_color *color, char *str);
bool		valid_double(t_data *s, double *data, char *str);
//===========================//
#endif
