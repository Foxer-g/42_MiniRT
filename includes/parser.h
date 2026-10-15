/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 08:24:04 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 19:08:33 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
//==========Parsing==========//
void		fill_ambient_lighting(t_data *s, t_parse *p, char **obj);
void		fill_cylinder(t_data *s, char **obj);
void		fill_triangle(t_data *s, char **obj);// a faire apres manda
void		fill_camera(t_data *s, char **obj);
void		fill_light(t_data *s, t_parse *p, char **obj);
void		fill_sphere(t_data *s, char **obj);
void		fill_plane(t_data *s, char **obj);
void		init_scene_object(t_data *s, uintmax_t i);

bool		check_line(t_data *s);
bool		check_scene(t_data *s);
bool		central_verif(t_data *scene, char **av);
bool		check_filename(const char *filename);
bool		extend_fail(t_header *header, void **arr, void *new_value);
bool		valid_color(t_data *s, char *str);
bool		valid_ratio(t_data *s, char *str);
bool		valid_coord(t_data *s, char *str);
bool		valid_vector(t_data *s, char *str);
bool		valid_fov(t_data *s, char *str);
bool		valid_brightness(t_data *s, char *str);
bool		valid_double(t_data *s, char *str);

t_cylinder	add_cylinder(void **obj, uintmax_t *i);
t_sphere	add_sphere(void **obj, uintmax_t *i);
t_plane		add_plane(void **obj, uintmax_t *i);
//===========================//
#endif
