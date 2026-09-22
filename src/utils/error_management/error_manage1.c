/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:51:16 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/22 17:16:03 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	error_perror(char *error, int type, int fd, int exit_code)
{
	if (type)
		perror("error");
	else
		ft_putstr_fd(error, fd);
	if (exit_code > -1)
		exit(exit_code);
}

bool	error_perror_b(char *error, int type, int fd, bool operator)
{
	if (type)
		perror("error");
	else
		ft_putstr_fd(error, fd);
	return (operator);
}

bool	error_message(char *error)
{
	ft_putstr_fd("error ", 2);
	ft_putstr_fd(error, 2);
	return (0);
}

int	malloc_error(int exit_code, int fd)
{
	if (fd >= 0)
		close(fd);
	ft_putstr_fd(ERR_MALOC, 2);
	exit (exit_code);
}

bool	error_file_rt(int *flag)
{
	if (*flag == CODE_RT_G)
		ft_putstr_fd(ERR_RT_G, 2);
	else if (*flag == CODE_RT_G)
		ft_putstr_fd(ERR_RT_G, 2);
	else if (*flag == CODE_RT_G)
		ft_putstr_fd(ERR_RT_G, 2);
	else if (*flag == CODE_RT_G)
		ft_putstr_fd(ERR_RT_G, 2);
	else if (*flag == CODE_RT_G)
		ft_putstr_fd(ERR_RT_G, 2);
	else if (*flag == CODE_RT_G)
		ft_putstr_fd(ERR_RT_G, 2);
	else if (*flag == CODE_RT_G)
		ft_putstr_fd(ERR_RT_G, 2);
	else if (*flag == CODE_RT_G)
		ft_putstr_fd(ERR_RT_G, 2);
	else if (*flag == CODE_RT_G)
		ft_putstr_fd(ERR_RT_G, 2);
	else if (*flag == CODE_RT_G)
		ft_putstr_fd(ERR_RT_G, 2);
	else if (*flag == CODE_RT_G)
		ft_putstr_fd(ERR_RT_G, 2);
	else if (*flag == CODE_RT_G)
		ft_putstr_fd(ERR_RT_G, 2);
	return (EXIT_FAILURE);
}

// int	data_malloc_error(t_data *data)
// {
// 	if (data)
// 		free_data(data);
// 	ft_putstr_fd(ERR_MALOC, 2);
// 	exit (EXIT_FAILURE);
// }