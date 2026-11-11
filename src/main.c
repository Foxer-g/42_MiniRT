/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 11:05:30 by ethutin-          #+#    #+#             */
/*   Updated: 2026/11/11 14:51:44 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	display_head(void *objs)
{
	t_header	*header;
	void		**array;

	header = (t_header *)objs - 1;
	array = (void **)objs;
	if (!array)
	{
		printf("%s===========%sHEADER_OBJS%s==========%s\n", D_RED, MAG, D_RED, RESET);
		printf("%stype	: %sY A RIEN!!!!%s\n", D_RED, ORANGE, RESET);
	}
	else
	{
		printf("%s===========%sHEADER_OBJS%s==========%s\n", D_RED, MAG, D_RED, RESET);
		printf("%stype	: %s%d%s\n", D_RED, ORANGE, header->type, RESET);
		printf("%scount	: %s%ju%s\n", D_RED, ORANGE, header->count, RESET);
		printf("%scap	: %s%ju%s\n", D_RED, ORANGE, header->capacity, RESET);
	}
}

int    main(int ac, char **av)
{
    t_data    *scene;

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
