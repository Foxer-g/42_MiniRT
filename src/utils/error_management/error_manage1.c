/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:51:16 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/23 19:04:00 by ethutin-         ###   ########.fr       */
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
	{
		ft_putstr_fd(error, 2);
		perror(ERR_PERROR);
		ft_putstr_fd(RESET, 2);
	}
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

bool	error_file_rt(char *error)
{
	ft_putstr_fd(ERR_RT_G, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(ERR_RT_END, 2);
	free(error);
	return (false);
}
