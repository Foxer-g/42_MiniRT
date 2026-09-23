/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:00:37 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/23 19:54:12 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_line(char **flag, char *line, int fd)
{
	int		i;
	char	*identifier;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	identifier = is_identifier(line + i, fd);
	if (identifier)
	{
		*flag = identifier;
		return (true);
	}
	return (false);
}

bool	check_scene(char **flag, int fd)
{
	char	*line;
	int 	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		*flag = NULL;
		i++;
		printf("line : %d\n", i);
		if (check_line(flag, line, fd))
		{
			free(line);
			get_next_line(-1);
			close(fd);
			return (true);
		}
		free(line);
	}
	get_next_line(-1);
	return (false);
}

bool	check_filename(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (ft_strncmp(&filename[len - 3], ".rt", 4) != 0)
		return (error_perror_b(ERR_FILNAM, P_ERROR, 2, true));
	return (false);
}

bool	central_verif(int ac, char **av)
{
	int		fd;
	char	*flag;

	if (ac != 2)
		return (error_perror_b(ERR_AC, P_ERROR, 2, true));
	else if (check_filename(av[1]))
		return (true);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		return (error_perror_b(ERR_OPEN_C_V, C_ERROR, 2, true));
	flag = NULL;
	if (check_scene(&flag, fd))
		return (error_file_rt(flag));
	close(fd);
	return (false);
}
