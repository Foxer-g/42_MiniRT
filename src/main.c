/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 11:05:30 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 16:54:05 by ethutin-         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data	*scene;

	if (ac != 2)
		return (error_perror_b(ERR_AC, __func__, P_ERROR, 2));
	scene = init_data();
	if (central_verif(scene, av) || render(scene))
	{
		free_data(scene);
		return (1);
	}
	// display_head(scene->objs);
	// print_param(scene);
	// print_struct(scene);
	free_data(scene);
	printf(D_RED"=========="MAG"END_OF_PROGRAM"D_RED"========="RESET"\n");
	return (0);
}

/* //////////TO_DO\\\\\\\\\\
-[X] continuer la verification de data
	-[X] -> identifier ne marche pas
	-[X] -> faire le premier proto de recup data
	-[X] -> identifier les leak dans filname, leak quand path incorrect
			<< ta oublier de free du con
	-[X] -> check le non renouvelemnt des base
	-[X] -> check la validiter de toutes les donnes dans data
		-[X] -> Ambient lighting
			-[X] -> refaire en utilisant direct split
				|-> "◦Each type of information from an element 
					can be separated by one or more spaces"
		-[X] -> Camera
		-[X] -> Light
		-[X] -> Sphere
		-[X] -> Plane
		-[X] -> Cylinder
		*[] -> Triangle
	-[X] -> faire la traduction du parse

-[X] terminer la construction de init et free
	-[X] -> finir free et init, ne pas oublier vector et obj et les objs
	-[X] -> voire avec F0xer si ca luis convient

-[X] strtod foire sur
	-[X] sur 0.
		<< ces une feature
	-[X] les - le mette en pls
		<< ta mis un unsign idiot

-[X]	etre sur de pas avoir fait de la merde en init objs avec PTR
		qui pourrait tout foutre en l'air
	-[O] -> ces la merde
	-[X] -> fausse alerte

-[X]	creer un nouveau systeme ou scene objs et un void * de struct
	-[O] version objs et scene_objs
		<< j'en ais plus rien a faire 
	-[X] version avec uniquement scene_objs
		<< j'avais fait de la merde
	
-[]		effectuer une fusion conluant entre render et les rest du code
	-[X] -> la init utilisation et free de la mlx bancale
	-[/] -> multiple fonction non terminer et indispensable
	-[/] -> avoir un truc qui compile est seg pas
	
-[X]	probleme memoire quand utilisation de  ft_extend_array_back
	-[X] pourquoi?
		<< quand ft_extend_array_back est utiliser 
			il initialise pas se qui a ete rajouter, j'ai changer sont malloc en calloc 
-[X]	erreur critique
	-[X] dans render il y a du tplane non initialiser
	-[X] dans central_draw le systeme de hookprovoque des erreur en cascade

-[O]	implementation des calculer de simulation
	-[] -> utilisation de offset_x dans les calcules utilisant coordinate.x 
	-[] -> utilisation de offset_y dans les calcules utilisant coordinate.y
	-[] -> utilisation de offset_x dans les calcules utilisant coordinate.z
	-[] -> utilisation de alpha dans les calcules utilisant vector.?
	-[] -> utilisation de beta dans les calcules utilisant vector.?
	-[] -> utilisation de gamma dans les calcules utilisant vector.?
	
=>	se souvenir
	|-> data->ambient non ititialiser dans init_data
	|-> gestion des object dans render n'est pas imuable et donc impropre
	|-> back_fnct_4.c et dedier a print est donc non essentielle
	|-> BE POSITIVE
*/