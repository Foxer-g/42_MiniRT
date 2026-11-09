/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:22:16 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 16:41:52 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//=====Color Reference To Use Everywhere=====//
# define RESET   "\e[0m"//It's like set but in revese
# define D_RED   "\e[1;38;2;187;6;6m"// You are my fluoroethylene methyl
# define MAG     "\e[1;38;2;242;0;255m"// I love magenta  F200FF mmh delicious
# define Z_BLUE  "\e[1;38;2;22;184;243m"// A life of work to know how to live
# define ORANGE  "\e[1;38;2;255;128;0m"// Strawberrie juice is good

# define RGBA_MAG 0xF200FFFF
# define RGBA_D_RED 0xBA0606FF
# define RGBA_L_BLUE 0x000FFFFFF
# define RGBA_DK_RED 0x590000FF
# define RGBA_BLACK 0x000000FF
//=====================================//

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
# define ERR_RT_INVALID_ORIENT "The orientation must be betwen [-1.0:1.0] IN "

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
# define ERR_REN_GEN_IMG "an error as happen IN "
# define ERR_IMPOSSIBLE_IMG "it is impossible to generate any image IN "
# define ERR_NEW_IMG "mlx_new_image as failed IN "
# define ERR_UNKNOW_OBJECT "A object provide to render is unknown IN "
/////////////////////////////////////

# define LOCAL '.'
# define SEP ','

# define DEF_HEIGHT 240
# define DEF_WIDTH 320
# define POS_X 0
# define POS_Y 0

# define DEFAULT_ALPHA 0.5235987756
# define DEFAULT_BETA 0.32
# define FPS 60
# define TITLE "Mongolian Rescue Therapy"
# define SPACE 5
# define PLUS_SCALE 1.03
# define MINUS_SCALE 0.97
# define Z_MAX 10.0
# define Z_MIN 0.0 
//================================================//

#endif
