/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 14:10:46 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/29 13:53:30 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	data_malloc_error(t_data *data, char *error)
{
	free_data(data);
	ft_putstr_fd(error, 2);
	exit (EXIT_FAILURE);
}

