/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:00:37 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/21 17:45:58 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// void    *fill_tmp_data(void) // a deplacer et comleter
// {
// 	return ;
// }

// bool	check_filename(const char *filename)
// {
// 	int	len;

// 	len = ft_strlen(filename);
// 	if (len <= 3)
// 		return (false);
// 	filename += len - 3;
// 	if (!ft_strncmp(filename, ".rt", 3))
// 		return (false);
// 	return (true);
// }

// int	color_parse(char *line, int j) //on fait pas l'hexa
// {
// 	int	max;

// 	if (line[j] == '\0' || line[j] == '\n')
// 		return (1);
// 	max = 0;
// 	line += j;
// 	if (ft_strncmp(line, ",0x", 3))
// 		return (0);
// 	j = 3;
// 	if (!ft_ishexa(line[j]))
// 		return (0);
// 	while (ft_ishexa(line[j]))
// 	{
// 		max++;
// 		j++;
// 	}
// 	if ((line[j] != '\0' && line[j] != '\n') || max > 8)
// 		return (0);
// 	return (1);
// }

// int	verif_data(char *line, int i, int j)
// {
// 	char	**tab;

// 	tab = ft_split(line, ' ');
// 	if (!tab)
// 		return (0);
// 	while (tab[++i])
// 	{
// 		j = 0;
// 		if (tab[i][0] == '\0')
// 			continue ;
// 		if (!ft_isoperator(tab[i][j]) && !ft_isdigit(tab[i][j]))
// 			return (error_verif(tab));
// 		if (ft_isoperator(tab[i][j]))
// 			j++;
// 		if (ft_isoperator(tab[i][j]))
// 			return (error_verif(tab));
// 		if (!ft_isdigit(tab[i][j]))
// 			return (error_verif(tab));
// 		while (ft_isdigit(tab[i][j]))
// 			j++;
// 		if (!color_parse(tab[i], j))
// 			return (error_verif(tab));
// 	}
// 	free_tab((void **)tab, i);
// 	return (1);
// }

// bool	verif_line (char *line)
// {
	
// }

// bool	verif_file(int fd)
// {
// 	char	*tmp;
// 	char	*line;

// 	while (1)
// 	{
// 		tmp = get_next_line(fd);
// 		if (!tmp)
// 			break ;
// 		line = ft_strtrim(tmp, "  \n");
// 		free(tmp);
// 		if (!line)
// 			return (0);
// 		if (!verif_atoi(line, -1, 0))
// 		{
// 			free(line);
// 			return (0);
// 		}
// 		free(line);
// 	}
// 	return (1);
// }


// bool	central_verif(int ac, char **av)
// {
// 	char	*tmp;
// 	char	*line;
// 	int		fd;

// 	if (ac != 2)
// 		return (error_perror_b(ERR_AC, P_ERROR, 2, true));
// 	else if (!check_filename(av[1]))
// 		error_perror_b(ERR_FILNAM, P_ERROR, 2, true);
// 	fd = open(av[1], O_RDWR);
// 	if (fd < 0)
// 		return ((ERR_OPEN, P_ERROR, 2, true));
// 	if ()
// 		return ((ERR_OPEN, P_ERROR, 2, true));

// 	tmp = get_next_line(fd);
// 	if (!tmp)
// 		malloc_error(EXIT_FAILURE);	
	
// 		line = ft_strtrim(tmp, "  \n");
// 	free(tmp);
// 	if (!line)
// 		malloc_error(EXIT_FAILURE);	
	
// 		if (!verif_atoi(line, -1, 0))
// 		malloc_open_map_error(-3, line, fd, NULL);
// 	free(line);
	
// 	if (!verif_line(fd))
// 		malloc_open_map_error(-3, NULL, fd, NULL);
// 	close(fd);
// 	return (false);
// }

// int	central_verif(int ac, char **av)
// {
// 	char	*tmp;
// 	char	*line;
// 	int		fd;

// 	if (ac != 2)
// 		return (ac_error());
// 	if (!filename(av[1]))
// 		return (file_name_error());
// 	fd = open(av[1], O_RDWR);
// 	if (fd < 0)
// 		not_open_error(fd, NULL);
// 	tmp = get_next_line(fd, 0);
// 	if (!tmp)
// 		malloc_open_map_error(-1, tmp, fd, NULL);
// 	line = ft_strtrim(tmp, "  \n");
// 	free(tmp);
// 	if (!line)
// 		malloc_open_map_error(-1, line, fd, NULL);
// 	if (!verif_atoi(line, -1, 0))
// 		malloc_open_map_error(-3, line, fd, NULL);
// 	free(line);
// 	if (!verif_line(fd))
// 		malloc_open_map_error(-3, NULL, fd, NULL);
// 	close(fd);
// 	return (1);
// }