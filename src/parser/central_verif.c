/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:00:37 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 18:51:46 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_line(t_data *s)
{
	if (ft_isvoid(s->p->line))
		return (false);
	s->p->obj = ft_split(s->p->line + leap_space(s->p->line), ' ');
	if (!s->p->obj)
		data_malloc_error_parse(s, __func__, true, NULL);
	if (!ft_strncmp(s->p->obj[0], "A", 2))
		fill_ambient_lighting(s, s->p, s->p->obj);
	else if (!ft_strncmp(s->p->obj[0], "C", 2))
		fill_camera(s, s->p->obj);
	else if (!ft_strncmp(s->p->obj[0], "L", 2))
		fill_light(s, s->p, s->p->obj);
	else if (!ft_strncmp(s->p->obj[0], "sp", 3))
		fill_sphere(s, s->p->obj);
	else if (!ft_strncmp(s->p->obj[0], "pl", 3))
		fill_plane(s, s->p->obj);
	else if (!ft_strncmp(s->p->obj[0], "cy", 3))
		fill_cylinder(s, s->p->obj);
	else if (!ft_strncmp(s->p->obj[0], "tr", 3))
		fill_triangle(s, s->p->obj);
	else
		error_generic_rt(s->p, ERR_NOT_IDENTIFIER, __func__);
	return (s->p->error);
}

bool	check_scene(t_data *s)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(s->p->fd);
		if (!tmp)
			break ;
		s->p->line = ft_strtrim(tmp, " \n");
		free (tmp);
		if (!s->p->line)
			data_malloc_error_parse(s, __func__, true, NULL);
		if (check_line(s))
		{
			get_next_line(-1);
			return (true);
		}
		free_parse(s->p, false);
	}
	get_next_line(-1);
	return (false);
}

bool	check_filename(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (!ft_strncmp(&filename[len - 3], ".rt", 4))
		return (false);
	return (true);
}

bool	central_verif(t_data *s, char **av)
{
	if (check_filename(av[1]))
		return (error_perror_b(ERR_FILNAME, __func__, P_ERROR, 2));
	s->p->fd = open(av[1], O_RDONLY);
	if (s->p->fd <= 0)
		return (error_perror_b(NULL, __func__, C_ERROR, 2));
	if (check_scene(s))
		return (true);
	if (s->p->fd >= 0)
		close(s->p->fd);
	init_scene(s);
	init_scene_object(s, -1);
	return (false);
}
