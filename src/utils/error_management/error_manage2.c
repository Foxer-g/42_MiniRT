/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 14:10:46 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/23 14:22:38 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void    data_malloc_error(void *data, unsigned nb_e)
{
	if (data)
			ft_free_nt_tab(data, nb_e);
	ft_putstr_fd(ERR_MALOC, 2);
	exit (EXIT_FAILURE);
}
