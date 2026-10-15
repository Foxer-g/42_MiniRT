/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:22:16 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/15 11:44:53 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//=====Color Reference To Use Everywhere=====//
# define RESET   "\e[0m"//It's like set but in revese
# define D_RED   "\e[1;38;2;187;6;6m"// You are my blueberries
# define MAG     "\e[1;38;2;242;0;255m"// I love magenta  F200FF mmh delicious
# define Z_BLUE  "\e[1;38;2;22;184;243m"// A life of work to know how to live
# define ORANGE  "\e[1;38;2;255;128;0m"// Strawberrie juice is good
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
# define NO_FD  -1
//-------------------//

/*---------------------ERR_REF---------------------*/
# define ERR_MALOC "a malloc as failed"
# define ERR_MLX "a mlx as failed"
# define ERR_WIN "a window as failed"

/////CENTRAL_VERIF/////
# define ERR_AC "You must enter one argument only\n ->\
 ./miniRT <xxxxxxx>.rt\nIN "
# define ERR_FILNAME "You must only enter a single file with a\
 .rt extension\n-> ./miniRT <xxxxxxx>.rt\nIN "
# define ERR_NOT_IDENTIFIER "Identifier not \
regognize please try with a valid one IN "

/////RATIO/////
# define ERR_RT_FORMAT_RATIO "Wrong format used, correct format x.x IN"
# define ERR_RT_INVALID_RATIO "The ratio must be betwen [0.0:1.0] IN "
# define ERR_RT_NO_RATIO "No ratio has been provided IN "
# define ERR_RT_INCORECT_RATIO "The ratio is not in the correct format IN "

/////DATA/////
# define ERR_ALREADY_USE "This identifier have already been provided, \
you must provide it one time only IN " 
# define ERR_RT_INVALID_DATA "the format of data given by \
the identifier is incorect IN "

/////COLOR/////
# define ERR_INVALID_COLOR "The colors provided are invalid, \
they must range in [0:255] IN "
# define ERR_INCORECT_COLOR "The colors provided are incorect, \
they must only used numerical caratere IN "
# define ERR_FORMAT_COLOR "Wrong format used, correct format xxx,xxx,xxx IN " 

/////COORD/////
# define ERR_RT_FORMAT_COORD "Wrong format used, correct format xxx,xxx,xxx "
# define ERR_RT_INCORECT_COORD "The coordonate are not \
in the correct format IN "
# define ERR_RT_VOID_COORD "No coordinnate as been provided IN "

/////FOV/////
# define ERR_RT_INVALID_FOV "The fov must be provide only with \
numerical betwen [0:180] caratere IN"
# define ERR_RT_INCORECT_FOV "The fov must be betwen [0:180] IN"
# define ERR_RT_FORMAT_FOV "Wrong format used, correct format x.x IN"

/////VECTOR/////
# define ERR_RT_INCORECT_VECTOR "A vector is not in the correct format IN "
# define ERR_RT_VOID_VECTOR "No vector as been provided IN "
# define ERR_RT_FORMAT_VECTOR "Wrong format used, correct format x.x,x.x,x.x IN"

/////DOUBLE/////
# define ERR_RT_VOID_DOUBLE "No double as been provided IN "
# define ERR_RT_INCORECT_DOUBLE "A double is not in the correct format IN "
# define ERR_RT_FORMAT_DOUBLE "Wrong format used, correct format x.x IN"

/////BRIGHTNESS/////
# define ERR_RT_VOID_BRIGHTNESS "No brightness as been provided IN "
# define ERR_RT_INVALID_BRIGHTNESS "The brightness is not in \
the correct format IN "
# define ERR_RT_INCORECT_BRIGHTNESS "The brightness must be betwen [0:1] IN"
# define ERR_RT_FORMAT_BRIGHTNESS "Wrong format used, correct format x.x IN"

/////RENDER/////
# define ERR_REN_GEN_IMG "an error as happen IN " //semi placeholder

# define ERR_PLACEHOLDER "PLACEHOLDER"
/////////////////////////////////////

# define LOCAL '.'
# define SEP ','
# define DEF_HEIGHT 15//160 // a voir si on les conserves
# define DEF_WIDTH 20//240 //
# define TITLE "Mongolian Rescue Therapy"
//================================================//

#endif
