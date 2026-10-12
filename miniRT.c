/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 11:05:30 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/12 10:31:28 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// void	get_display(char **arr) //a degager a la fin 

// {
// 	int	j;

// 	j = -1;
// 	printf("%s==========DISPLAY==========%s\n", MAG, RESET);
// 	while (arr[++j])
// 		ft_printf("%s%d : %s{%s}%s\n", D_RED, j, ORANGE, arr[j], RESET);
// }

// static void	display_objs(void *objs) // a degager a la fin //obsolete mais peux donner une image
// {
// 	t_header	*header;
// 	uintmax_t	i;
// 	void		**array;

// 	if (!objs)
// 	{
// 		ft_printf("il y a que dalle\n");
// 		return ;
// 	}
// 	header = (t_header *)objs - 1;
// 	array = (void **)objs;
// 	ft_printf("%s===========HEADER==========%s\n", MAG, RESET);
// 	ft_printf("%stype     : %s%d%s\n", D_RED, ORANGE, header->type, RESET);
// 	ft_printf("%scount    : %s%ju%s\n", D_RED, ORANGE, header->count, RESET);
// 	ft_printf("%scapacity : %s%ju%s\n", D_RED, ORANGE, header->capacity, RESET);
// 	i = -1;
// 	ft_printf("%s============OBJS===========%s\n", MAG, RESET);
// 	while (++i < header->count)
// 		ft_printf("%s%ju : %s{%s}%s\n", D_RED, i + 1, \
// ORANGE, (char *)array[i], RESET);
// 	ft_printf("%s===========================%s\n", MAG, RESET);
// }

void	print_value(void *value, t_type type)// a degager a la fin, elle est utiliser dans add_obj
{
	if (type == PTR)
		printf("%sPTR	: %s[%s]%s\n", D_RED, ORANGE, (char *)value, RESET);
	else if (type == N8)
		printf("%sN8	: %s[%u]%s\n", D_RED, ORANGE, *(uint8_t *)value, RESET);
	else if (type == N16)
		printf("%sN16: %s[%u]%s\n", D_RED, ORANGE, *(uint16_t *)value, RESET);
	else if (type == N32)
		printf("%sN32	: %s[%u]%s\n", D_RED, ORANGE, *(int *)value, RESET);
	else if (type == N64)
		printf("%sN64: %s[%lu]%s\n", D_RED, ORANGE, *(uint64_t *)value, RESET);
	else if (type == FLOAT)
		printf("%sFLOAT	: %s[%f]%s\n", D_RED, ORANGE, *(float *)value, RESET);
	else if (type == DOUBLE)
		printf("%sDOUBLE	: %s[%f]%s\n", \
D_RED, ORANGE, *(double *)value, RESET);
	else if (type == LDOUBLE)
		printf("%sLDOUBLE	: %s[%Lf]%s\n", \
D_RED, ORANGE, *(long double *)value, RESET);
}

static void	display_head(void *objs)
{
	t_header	*header;
	void		**array;

	header = (t_header *)objs - 1;
	array = (void **)objs;
	printf("%s===========HEADER==========%s\n", MAG, RESET);
	printf("%stype	: %s%d%s\n", D_RED, ORANGE, header->type, RESET);
	printf("%scount	: %s%ju%s\n", D_RED, ORANGE, header->count, RESET);
	printf("%scap	: %s%ju%s\n", D_RED, ORANGE, header->capacity, RESET);
}

int	main(int ac, char **av)
{
	t_data	*scene;

	if (ac != 2)
		return (error_perror_b(ERR_AC, __func__, P_ERROR, 2));
	scene = init_data();
	if (!scene)
		malloc_error(1, NO_FD);
	if (central_verif(scene, av))
	{
		free_data(scene);
		return (1);
	}
	display_head(scene->objs); // a degager a la fin
	free_data(scene);
	printf(ORANGE "==========END OF PROGRAM=========\n" RESET);
	return (0);
}

/* TO DO
- continuer la verification de data
	[X] -> identifier ne marche pas
	[X] -> faire le premier proto de recup data
	[X] -> identifier les leak dans filname, leak quand path incorrect
			<< ta oublier de free du con
	[X] -> check le non renouvelemnt des base
	[X] -> check la validiter de toutes les donnes dans data
		-[X] -> Ambient lighting
			[X] -> refaire en utilisant direct split
				|-> ◦Each type of information from an element 
					can be separated by one or more spaces
		-[X] -> Camera
		-[X] -> Light
		-[X] -> Sphere
		-[X]	-> Plane
		-[X] -> Cylinder
		*[] -> Triangle
	[X] -> faire la traduction du parse

- terminer la construction de init et free
	[X] -> finir free et init, ne pas oublier vector et obj et les objs
	[X] -> voire avec F0xer si ca luis convient


- strtod foire sur
	-> [X] sur 0.
		<< ces une feature
	-> [X] les - le mette en pls
		<< ta mis un unsign idiot

- etre sur de pas avoir fait de la merde en init objs avec PTR
	qui pourrait tout foutre en l'air
	[O] -> ces la merde
	[X] -> ces moin la merde


- [X] BE POSITIVE
*/
