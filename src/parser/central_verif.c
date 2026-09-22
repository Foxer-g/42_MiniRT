/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:00:37 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/22 18:15:19 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_filename(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len <= 3)
		return (true);
	filename += len - 3;
	if (!ft_strncmp(filename, ".rt", 3))
		return (false);
	return (true);
}

	// char	**tab;

	// tab = ft_split(line, ' ');
	// if (!tab)
	// 	return (0);
	// while (tab[++i])
	// {
	// 	j = 0;
	// 	if (tab[i][0] == '\0')
	// 		continue ;
	// 	if (!ft_isoperator(tab[i][j]) && !ft_isdigit(tab[i][j]))
	// 		return (error_verif(tab));
	// 	if (ft_isoperator(tab[i][j]))
	// 		j++;
	// 	if (ft_isoperator(tab[i][j]))
	// 		return (error_verif(tab));
	// 	if (!ft_isdigit(tab[i][j]))
	// 		return (error_verif(tab));
	// 	while (ft_isdigit(tab[i][j]))
	// 		j++;
	// 	if (!color_parse(tab[i], j))
	// 		return (error_verif(tab));
	// }
	// free_tab((void **)tab, i);
	// return (1);


bool	verif_line(int *flag_line, int *nb_e, int fd)
{
	char *tmp;
	char *line;

	tmp = get_next_line(fd);
	if (!tmp)
		malloc_error(EXIT_FAILURE, fd);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		line = ft_strtrim(tmp, " \n");
		free(tmp);
		if (!line)
			malloc_error(EXIT_FAILURE, fd);
		if (verif_data(line, flag_line, nb_e))
		{
			return (true);
			get_next_line(-1);
		}
		free(line);
	}
	get_next_line(-1);
	return(false);
}
	// tmp_line = get_next_line(fd);
	//     if (!tmp_line)
	// 	    malloc_open_map_error(-2, tmp_line, fd, data);
	// line = ft_strtrim(tmp_line, " \n");
	// free(tmp_line);
	// data->map->columns = parse_column(line, data->map);
	// if (data->map->columns <= 0)
	// 	malloc_open_map_error(-3, line, fd, data);
	// free(line);
	// while (1)
	// {
	// 	tmp_line = get_next_line(fd, 0);
	// 	if (!tmp_line)
	// 		break ;
	// 	line = ft_strtrim(tmp_line, " \n");
	// 	free(tmp_line);

	// 	free(line);
	// }

bool	central_verif(int ac, char **av, int *nb_e)
{
	int		fd;
	int     flag_line;

	if (ac != 2)
		return (error_perror_b(ERR_AC, P_ERROR, 2, true));
	else if (check_filename(av[1]))
		error_perror_b(ERR_FILNAM, P_ERROR, 2, true);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (error_perror_b(ERR_OPEN, P_ERROR, 2, true));
	if (verif_line(&flag_line, nb_e, fd))
		return (error_file_rt(&flag_line));
	close(fd);
	return (false);
}
