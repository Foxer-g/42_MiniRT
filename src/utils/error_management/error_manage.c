/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:51:16 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/14 18:12:08 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_perror_b(char *error, const char *loc, int type, int fd)
{
	if (fd < 0)
		fd = 2;
	if (type)
	{
		perror(D_RED "[Error] " ORANGE);
		ft_putstr_fd("IN " Z_BLUE, fd);
		ft_putstr_fd(loc, fd);
		ft_putstr_fd(RESET "\n", fd);
	}
	else
	{
		ft_putstr_fd(D_RED "[Error] " ORANGE, fd);
		ft_putstr_fd(error, fd);
		ft_putstr_fd(Z_BLUE, fd);
		ft_putstr_fd(loc, fd);
		ft_putstr_fd(RESET "\n", fd);
	}
	return (true);
}

void	data_malloc_error_parse\
(t_data *data, const char *location, bool gnl, char **arr)
{
	if (gnl)
		get_next_line(-1);
	if (arr)
		free_nt_arr (arr);
	free_data(data);
	ft_putstr_fd(D_RED "[Error] " ORANGE \
"a malloc as failed " ORANGE "IN " Z_BLUE, 2);
	ft_putstr_fd(location, 2);
	ft_putstr_fd(RESET"\n", 2);
	exit (EXIT_FAILURE);
}

void	data_malloc_error\
(t_data *data, char *error, const char *location)
{
	free_data(data);
	ft_putstr_fd(D_RED "[Error] " ORANGE, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(" IN " Z_BLUE, 2);
	ft_putstr_fd(location, 2);
	ft_putstr_fd(RESET"\n", 2);
	exit (EXIT_FAILURE);
}

int	malloc_error(const char *location, int exit_code, int fd)
{
	if (fd >= 0)
		close(fd);
	ft_putstr_fd(D_RED "[Error] " ORANGE \
"a malloc as failed " ORANGE "IN " Z_BLUE, 2);
	ft_putstr_fd(location, 2);
	ft_putstr_fd(RESET "\n", 2);
	exit (exit_code);
}
