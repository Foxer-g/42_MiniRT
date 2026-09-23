/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 11:05:30 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/23 19:57:25 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	//void			*data;

	if (central_verif(ac, av))
		return (1);
	//data = data_filler();
	// render
	//ft_arr_free(data);
	//ft_printf(OUI);
	ft_printf("end of program\n");
	return (0);
}

/* TO DO
continuer la verification de data
regler l'erreur dans check_identifie, marche pas 
*/