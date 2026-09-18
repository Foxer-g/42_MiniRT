/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:12:10 by toespino          #+#    #+#             */
/*   Updated: 2026/09/18 12:54:07 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int32_t main(int32_t ac, char ** av)
{
	t_data	scene;

	if (ac == 2)
	{
		if (!parse_input)
			return (1);
		while (window)
		{
			scene = calculate_scene();
			render(scene);
		}
	}
	else
		printf("\e[31mWrong usage :\e[0m must be used as with a unique argument");
	return (0);
}
