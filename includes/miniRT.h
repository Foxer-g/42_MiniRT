/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:12:29 by toespino          #+#    #+#             */
/*   Updated: 2026/09/29 13:49:34 by ethutin-         ###   ########.fr       */
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
//--------CODE-------//
# define P_ERROR	0
# define C_ERROR	1
# define NF 		-1

# define MALLOC_ERR 0 

# define IDENTIFIER_CODE 1
// # define _CODE 2
// # define _CODE 3
// # define _CODE 4
// # define _CODE 5
// # define _CODE 6
//-------------------//

/*---------------------ERR_CODE---------------------*/
# define ERR_END_ERR D_RED "] "
# define ERR_START_ERR D_RED "["

# define ERR_RT_G D_RED "Error\n["ORANGE
# define ERR_RT_IDENTIFIER D_RED "] " ORANGE "is not a valid identifier\n" RESET
# define ERR_RT_DATA_TYPE D_RED "] [" ORANGE
# define ERR_RT_DATA_VALUE D_RED "] " ORANGE "is not a valid value\n" RESET

# define ERR_OPEN_C_V GREEN "[" ORANGE "IN " Z_BLUE "CENTRAL_VERIF "\
ORANGE "BY " Z_BLUE "ERROR_PERROR_B" GREEN "] " RESET

# define ERR_RT D_RED"Error\n"RESET
# define ERR_DATA_RT    ORANGE "IN " Z_BLUE "FILL_AMBIENT_LIGHTING_DATA " ORANGE "BY " Z_BLUE

# define ERR_MALOC D_RED "[Error] " ORANGE "A malloc has failed\n"RESET

# define ERR_AC D_RED "[Error] " ORANGE "You must enter one argument only\n\
-> ./miniRT <xxxxxxx>.rt\n"RESET

# define ERR_FILNAME D_RED "[Error] " ORANGE "You must only enter a single file with a \
.rt extension\n-> ./miniRT <xxxxxxx>.rt\n"RESET

# define ERR_PERROR D_RED "[Error] " ORANGE

//___in_init_files___//
# define ERR_INIT_DA D_RED "[Error] " ORANGE  "a malloc as failed " ORANGE "IN " \
Z_BLUE "t_data	*init_data(void)\n" RESET
# define ERR_INIT_PA D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "t_parse	*init_parse(t_data	*s)\n" RESET
# define ERR_INIT_LI D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "t_light	*init_light(t_data *data)\n" RESET
# define ERR_INIT_CO D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "t_coordinate	init_coodinate(t_data *data)\n" RESET
# define ERR_INIT_AM D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "t_amb	init_ambient(t_data *data)\n" RESET
# define ERR_INIT_COL D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "t_color	init_color(t_data *data)\n" RESET
# define ERR_INIT_CY D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "t_cylinder	*init_cylinder(t_data *data)\n" RESET
# define ERR_INIT_SP D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "t_sphere	*init_sphere(t_data *data)\n" RESET
# define ERR_INIT_PL D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "t_plane	*init_plane(t_data *data)\n" RESET
# define ERR_INIT_OB D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "void	*init_objs(t_data *data)\n" RESET

# define ERR_INIT_IDENTIFIER D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "void	check_line(t_data *s)\n" RESET
# define ERR_INIT_NIDENTIFIER D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "void	is_identifier(t_data *s)\n" RESET
# define ERR_INIT_DATA_LINE D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "void	identifier_selector(t_data *s, int i)\n" RESET

# define ERR_INVALID_COLOR D_RED "[Error] " ORANGE "The colors provided are invalid " ORANGE "IN " \
Z_BLUE "void	identifier_selector(t_data *s, int i)\n" RESET

# define ERR_ADD_DATA D_RED "[Error] " ORANGE "a malloc as failed " ORANGE "IN " \
Z_BLUE "void	add_data_to_objs(t_data *scene, char *data)\n" RESET
/*--------------------------------------------------*/

# define OUI D_RED "[" MAG"MAIN"D_RED"] " Z_BLUE "TOUT VAS BIEN\n"RESET
# define END ORANGE "END OF PROGRAM\n" RESET
//================================================//

//==========Generic Fonction==========//
bool 	valid_color(t_color color);

void	ad_data_to_objs(t_data *s, void **arr, void *value);
//
void	*ft_init_array_back(t_elem elem);
void	*ft_realloc_back(void *ptr, uintmax_t old_size, uintmax_t new_size);
void	*ft_extend_array_back(void **arr);
//
//===================================//

//====For Initialization And Free====//
t_data	        *init_data(void);
t_parse	        *init_parse(t_data *data);
t_light         *init_light(t_data *data);
t_coordinate	init_coordinate(void);
t_amb           init_ambient(void);
t_color         init_color(void);

void            *init_objs(t_data *data);
void            free_data(t_data *data);
void            free_parse(t_parse *parse, bool complete);
void            free_light(t_light *light);
//===================================//


//==========Error Managenment==========//
void	*central_filler(int fd);

void	data_malloc_error(t_data *data, char *error);
void	error_perror(char *error, int type, int fd, int exit_code);
void	error_identifier_rt(t_parse *p);
void	error_rt_selection(t_parse *p);

int		malloc_error(int exit_code, int fd);

bool	error_perror_b(char *error, int type, int fd, bool operator);
bool	error_message(char *error);
//=====================================//

//==========Renderer==========//
void	render(void);
//============================//

//==========Parsing==========//

void    fill_ambient_lighting(t_data *s, t_parse *p);
void    fill_cylinder(t_data *s, t_parse *p);
void    fill_triangle(t_data *s, t_parse *p);// a faire apres manda
void    fill_camera(t_data *s, t_parse *p);
void    fill_light(t_data *s, t_parse *p);
void    fill_sphere(t_data *s, t_parse *p);
void    fill_plane(t_data *s, t_parse *p);
void	identifier_selector(t_data *s, t_parse *p, int i);

bool    is_identifier(t_data *s);
bool	check_line(t_data *s);
bool	check_scene(t_data *s);
bool	central_verif(t_data *scene, char **av);
bool	check_filename(const char *filename, t_data *data);
//===========================//

#endif
