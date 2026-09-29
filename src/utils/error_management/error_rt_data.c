/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_rt_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 13:53:18 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/29 13:59:29 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	error_identifier_rt(t_parse *p)
{
	ft_putstr_fd(ERR_RT_G, 2);
	ft_putstr_fd(p->identifier, 2);
	ft_putstr_fd(ERR_RT_IDENTIFIER, 2);
	p->error = true;
}
