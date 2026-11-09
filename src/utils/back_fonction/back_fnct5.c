/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_fnct5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:11:01 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 17:04:51 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_k_arrow(int64_t key)
{
	return (key == K_RIGHT || key == K_LEFT || key == K_UP
		|| key == K_DOWN || key == K_KP_4 || key == K_KP_5 || key == K_KP_6
		|| key == K_KP_7 || key == K_KP_8 || key == K_KP_9);
}
