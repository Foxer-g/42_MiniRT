/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:00:37 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/29 14:01:59 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_line(t_data *s)
{
	int		i;

	i = 0;
	while (ft_isspace(s->p->line[i]) || s->p->line[i] == '\n')
		i++;
	if (!s->p->line[i])
		return (false);
	s->p->identifier = ft_strdup(s->p->line + i);
	if (!s->p->identifier)
		data_malloc_error(s, ERR_INIT_IDENTIFIER);
	return (is_identifier(s));
}

bool	check_scene(t_data *s)
{
	while (1)
	{
		s->p->line = get_next_line(s->p->fd);
		if (!s->p->line)
			break ;
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

bool	check_filename(const char *filename, t_data *data)
{
	int	len;

	len = ft_strlen(filename);
	if (ft_strncmp(&filename[len - 3], ".rt", 4) != 0)
	{
		free_data(data);
		return (true);
	}
	return (false);
}

bool	central_verif(t_data *s, char **av)
{
	if (check_filename(av[1], s))
		return (error_perror_b(ERR_FILNAME, P_ERROR, 2, true));
	s->p->fd = open(av[1], O_RDONLY);
	if (s->p->fd <= 0)
	{
		free_data(s);
		return (error_perror_b(ERR_OPEN_C_V, C_ERROR, 2, true));
	}
	if (check_scene(s))
		return (true);
	close(s->p->fd);
	return (false);
}
