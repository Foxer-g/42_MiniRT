/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:12:29 by toespino          #+#    #+#             */
/*   Updated: 2026/09/23 19:58:41 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"
# include "type.h"

# include <stdio.h>

//=====Color Reference To Use Everywhere=====//
# define RESET		"\e[0m"
# define BLACK		"\e[48;2;0;0;0m"
# define RED		"\e[31"
# define D_RED		"\e[1;38;2;187;6;6m"
# define DK_RED		"\e[1;38;2;89;0;0m"
# define MAG		"\e[1;38;2;242;0;255m"	// I love magentaF200FF
# define GREEN		"\e[32m"
# define L_GREEN	"\e[1;38;2;39;245;73m"	// we need more greeeeeeeeeeen
# define L_BLUE		"\e[1;38;2;0;255;255m"
# define Z_BLUE		"\e[1;38;2;22;184;243m"	// alife of work to know how tolive
# define ORANGE		"\e[1;38;2;255;128;0m"	// strawberrie juice is good
# define L_YELLOW	"\e[1;38;2;251;255;0m"	// yellow blind my favorite
# define L_Y_G		"\e[1;38;2;45;0;073m"	// no idea
# define PINKO		"\e[1;38;2;255;0;144m"	// pinko flaminko
# define RESET_C	"\e[0m"					// pinko flaminko
//=====================================//

//======<key_code>======//
// to quit,rotate,set parameter and scale with the key
# define KEY_ESCAPE 65307
# define KEY_BACKSPACE 65288
# define KEY_SPACE 32 
# define KEY_A 97
# define KEY_B 98
# define KEY_C 99
# define KEY_D 100
# define KEY_E 101
# define KEY_N 110
# define KEY_Q 113
# define KEY_R 114
# define KEY_S 115
# define KEY_V 118
# define KEY_W 119
# define KEY_Z 122
# define KEY_SLASH 65455
# define KEY_STAR 65450
# define KEY_DELETE 65439
// to move using arrow
# define KEY_ARROW_L 65361
# define KEY_ARROW_R 65363
# define KEY_ARROW_U 65362
# define KEY_ARROW_D 65364
//to use the mouse
# define M_CLK_L 1
# define M_CLK_M 2
# define M_CLK_R 3
# define M_SCR_U 4
# define M_SCR_D 5
// to zoom on and zoom out by key
# define KEY_0 65438
# define KEY_1 65436
# define KEY_2 65433
# define KEY_3 65435
# define K_NP_MIN 45
# define K_NP_MIN_2 65453
# define K_NP_PLU 61
# define K_NP_PLU_2 65451
//===================//

//=============<for general utility>=============//
# define P_ERROR	0
# define C_ERROR	1
# define NF 		-1

# define ERR_RT_G D_RED "Error\n["ORANGE
# define ERR_RT_END D_RED "] " ORANGE "is not a valid identifier\n" RESET

# define ERR_OPEN_C_V GREEN "[" ORANGE "IN " Z_BLUE "CENTRAL_VERIF "\
ORANGE "BY " Z_BLUE "ERROR_PERROR_B" GREEN "] " RESET


# define ERR_RT D_RED"Error\n"RESET

# define ERR_MALOC D_RED "[Error] " ORANGE "A malloc has failed\n"RESET

# define ERR_AC D_RED "[Error] " ORANGE "You must enter one argument only\n\
-> ./miniRT <xxxxxxx>.rt\n"RESET

# define ERR_FILNAM D_RED "[Error] " ORANGE "You must only enter a single file with\
.rt extension\n-> ./miniRT <xxxxxxx>.rt\n"RESET

# define ERR_PERROR D_RED "[Error] " ORANGE

# define OUI D_RED "[" MAG"MAIN"D_RED"] " Z_BLUE "TOUT VAS BIEN\n"RESET

//================================================//

//==========//////////////////////////////////////==========//

//==========================================================//

//==========Error Managenment==========//
void	*central_filler(int fd);

void	error_perror(char *error, int type, int fd, int exit_code);
void	data_malloc_error(void *data, unsigned int nb_e);

int		malloc_error(int exit_code, int fd);

bool	error_perror_b(char *error, int type, int fd, bool operator);
bool	error_message(char *error);
bool	error_file_rt(char *flag);
//=====================================//

//==========Renderer==========//
void	render(void);
//============================//

//==========Parsing==========//
char	*is_identifier(char *word, int fd);

void	fill_tmp_data(void *tmp_data);

bool	check_line(char **flag, char *line, int fd);
bool	check_scene(char **flag, int fd);
bool	data_verif(char *line, int *flag_line, int *nb_e);
bool	central_verif(int ac, char **av);
bool	check_filename(const char *filename);
//===========================//

#endif
