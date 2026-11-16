/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 11:05:30 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/16 14:46:01 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	t_data	*scene;

	if (ac != 2)
		return (error_perror_b(ERR_AC, __func__, P_ERROR, 2));
	scene = init_data();
	if (central_verif(scene, av))
	{
		free_data(scene);
		return (1);
	}
	init_mlx(scene);
	mlx_option(scene);
	get_hook(scene);
	if (render(scene))
	{
		free_data(scene);
		return (1);
	}
	mlx_loop(scene->mlx->mlx);
	free_data(scene);
	printf(D_RED"=========="MAG"END_OF_PROGRAM"D_RED"========="RESET"\n");
	return (0);
}
