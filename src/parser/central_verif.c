/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:00:37 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/12 16:51:23 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_line(t_data *data)
{
	if (ft_isvoid(data->p->line))
		return (false);
	data->p->obj = ft_split(data->p->line + leap_space(data->p->line), ' ');
	if (!data->p->obj)
		data_malloc_error_parse(data, __func__, true, NULL);
	if (!ft_strncmp(data->p->obj[0], "A", 2))
		fill_ambient_lighting(data, data->p, data->p->obj);
	else if (!ft_strncmp(data->p->obj[0], "C", 2))
		fill_camera(data, data->p, data->p->obj);
	else if (!ft_strncmp(data->p->obj[0], "L", 2))
		fill_light(data, data->p, data->p->obj);
	else if (!ft_strncmp(data->p->obj[0], "sp", 3))
		fill_sphere(data, data->p->obj);
	else if (!ft_strncmp(data->p->obj[0], "pl", 3))
		fill_plane(data, data->p->obj);
	else if (!ft_strncmp(data->p->obj[0], "cy", 3))
		fill_cylinder(data, data->p->obj);
	else
		error_generic_rt(data->p, ERR_NOT_IDENTIFIER, __func__);
	return (data->p->error);
}

bool	check_scene(t_data *data)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(data->p->fd);
		if (!tmp)
			break ;
		data->p->line = ft_strtrim(tmp, " \n");
		free (tmp);
		if (!data->p->line)
			data_malloc_error_parse(data, __func__, true, NULL);
		if (check_line(data))
		{
			get_next_line(-1);
			return (true);
		}
		free_parse(data->p, false);
	}
	get_next_line(-1);
	return (false);
}

bool	check_filename(const char *filename, char *extension)
{
	u_int32_t	l_file;
	u_int32_t	l_ext;

	l_file = ft_strlen(filename);
	l_ext = ft_strlen(extension);
	if (!ft_strncmp(&filename[l_file - l_ext], extension, l_ext + 1))
		return (false);
	return (true);
}

bool	central_verif(t_data *data, char **av)
{
	if (check_filename(av[1], ".rt"))
		return (error_perror_b(ERR_FILNAME, __func__, P_ERROR, 2));
	data->p->fd = open(av[1], O_RDONLY);
	if (data->p->fd <= 0)
		return (error_perror_b(NULL, __func__, C_ERROR, 2));
	if (check_scene(data))
		return (true);
	if (data->p->fd >= 0)
		close(data->p->fd);
	if (data->p->al && data->p->c && data->p->l)
		return (false);
	else
		return (error_generic(ERR_NO_PARAM, __func__, true));
}
