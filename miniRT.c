/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 11:05:30 by ethutin-          #+#    #+#             */
/*   Updated: 2026/09/29 15:04:39 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	display_objs(void *objs)// a degager a la fin 
{
	t_header	*header;
	uintmax_t	i;
	void		**array;
	
	if (!objs)
	{
		ft_printf("il y a que dalle\n");
		return ;
	}
	header = (t_header *)objs - 1;
	array = (void **)objs;
	ft_printf("HEADER\n");
	ft_printf("type     : %d\n", header->type);
	ft_printf("count    : %lu\n", header->count);
	ft_printf("capacity : %lu\n", header->capacity);
	i = -1;
	ft_printf("============OBJS===========\n");
	while (++i < header->count)
		ft_printf("%lu : [%p]\n", i, array[i]);
	ft_printf("===========================\n");
}

int	main(int ac, char **av)
{
	t_data	*scene;	

	if (ac != 2)
		return (error_perror_b(ERR_AC, P_ERROR, 2, true));
	scene = init_data();
	if (central_verif(scene, av))
	{
		free_data(scene);
		return (1);
	}
	
	display_objs(scene->objs);
	free_data(scene);
	ft_printf(END);
	
	return (0);
}
