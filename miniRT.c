/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 11:05:30 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 19:09:55 by ethutin-         ###   ########.fr       */
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

void	print_value(void *value, t_type type)//utiliser dans ad_data_to_objs
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

void	print_struct(t_st_type type)// elle est utiliser dans ad_data_scene_objs
{
	if (type == SPH)
		printf("%sSTRUCT : %s[SPH]%s\n", D_RED, ORANGE, RESET);
	else if (type == PLA)
		printf("%sSTRUCT : %s[PLA]%s\n", D_RED, ORANGE, RESET);
	else if (type == CYL)
		printf("%sSTRUCT : %s[CYL]%s\n", D_RED, ORANGE, RESET);
}

static void	display_head(void *objs)
{
	t_header	*header;
	void		**array;

	header = (t_header *)objs - 1;
	array = (void **)objs;
	printf("%s===========%sHEADER%s==========%s\n", D_RED, MAG, D_RED, RESET);
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
	if (central_verif(scene, av))
	{
		free_data(scene);
		return (1);
	}
	if (render(scene, -1, -1))
	{
		free_data(scene);
		return (1);
	}
	display_head(scene->objs);
	free_data(scene);
	printf(D_RED"=========="MAG"END_OF_PROGRAM"D_RED"========="RESET"\n");
	return (0);
}

/* //////////TO_DO\\\\\\\\\\
-[X] continuer la verification de data
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
		-[X] -> Plane
		-[X] -> Cylinder
		*[] -> Triangle
	[X] -> faire la traduction du parse

-[X] terminer la construction de init et free
	[X] -> finir free et init, ne pas oublier vector et obj et les objs
	[X] -> voire avec F0xer si ca luis convient

-[X] strtod foire sur
	-> [X] sur 0.
		<< ces une feature
	-> [X] les - le mette en pls
		<< ta mis un unsign idiot

-[X] etre sur de pas avoir fait de la merde en init objs avec PTR
	qui pourrait tout foutre en l'air
	[O] -> ces la merde
	[X] -> ces moin la merde


===> [X]creer un nouveau systeme ou scene objs et un void * de struct
		-[X] version objs et scene_objs
			<< j'en ais plus rien a faire 
		-[O] version avec uniquement scene_objs
	
-[] effectuer une fusion conluant entre render et les rest du code
	[] -> la init utilisation et free de la mlx bancale
	[/] -> multiple fonction non terminer et indispensable
	[/] -> avoir un truc qui compile est seg pas

-> se souveneir que data->ambient n'ait jamais initialiser dans init_data
	|-> //data->ambient = NULL;
- [X] BE POSITIVE
*/
