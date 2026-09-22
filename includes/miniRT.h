/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:12:29 by toespino          #+#    #+#             */
/*   Updated: 2026/09/21 14:37:23 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "type.h"
# include <stdio.h>

//=====Color Reference To Use Everywhere=====//
# define RESET		"\e[0m"
# define BLACK		"\e[48;2;0;0;0m"
# define RED		"\e[31"
# define D_RED		"\e[1;38;2;187;6;6m"
# define DK_RED		"\e[1;38;2;89;0;0m"
# define MAG		"\e[1;38;2;242;0;255m"	//I love magentaF200FF
# define GREEN		"\e[32m"
# define L_GREEN 	"\e[1;38;2;39;245;73m"	//we need more greeeeeeeeeeen
# define L_BLUE 	"\e[1;38;2;0;255;255m"
# define Z_BLUE 	"\e[1;38;2;22;184;243m"	//a life of work to know how to live
# define ORANGE		"\e[1;38;2;255;128;0m"	//strawberrie juice is good
# define L_YELLOW	"\e[1;38;2;251;255;0m"	//yellow blind my favorite
# define L_Y_G		"\e[1;38;2;45;0;073m"	//no idea
# define PINKO		"\e[1;38;2;255;0;144m"	//pinko flaminko
//=====================================//

//=============<for general utility>=============//
# define P_ERROR	0
# define C_ERROR	1
# define NF 		-1

# define DATA_ER	"\e[1;38;2;255;0;144mError : A malloc has failed\n"
# define ERR_AC		"\e[1;38;2;255;0;144mError : You must enter one argument\
only\n -> ./miniRT <xxxx>.rt\n"
//================================================//

//==========//////////////////////////////////////==========//
void	error_perror(char *error, int type, int fd, int exit_code);

bool	central_verif(int ac, char **av);
//==========================================================//

#endif
