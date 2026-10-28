/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:10:41 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 17:00:14 by ethutin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_H
# define HANDLE_H

//==========Handle==========//
void	mlx_option(t_data *s);
void	get_hook(t_data *data);
void	central_keypress(int key, void *param);
void	central_keyup(int key, void *param);
void	key_rotate(t_data *data, int key);
void	zoom(t_data *data, int key);
void	arrow_move(t_data *data, int key);
void	z_scale(t_data *data, int key);
void	reset_sim(t_data *data);
void	central_window(int key, void *param);
void	central_mouse(int key, void *param);
void	central_mouse_up(int key, void *param);
void	zoom_mouse(t_data *data, t_ren *r, int key);
void	z_scale_mouse(t_data *data, int key);
void	key_print(t_data *data, int key);//pas obligatoire

bool	generate_img(t_data *data);
//============================//

//==========Utils==========//
void	update_pos(t_data *data, uint8_t type, int space);
//============================//

//======<key_code>======//
# define K_CROSS  			    0
# define K_A					4
# define K_B					5
# define K_C					6
# define K_D					7
# define K_E					8
# define K_F					9
# define K_G					10
# define K_H					11
# define K_I					12
# define K_J					13
# define K_K					14
# define K_L					15
# define K_M					16
# define K_N					17
# define K_O					18
# define K_P					19
# define K_Q					20
# define K_R					21
# define K_S					22
# define K_T					23
# define K_U					24
# define K_V					25
# define K_W					26
# define K_X					27
# define K_Y					28
# define K_Z					29
# define K_1					30
# define K_2					31
# define K_3					32
# define K_4					33
# define K_5					34
# define K_6					35
# define K_7					36
# define K_8					37
# define K_9					38
# define K_0					39
# define K_RETURN				40
# define K_ENTER				40
# define K_ESCAPE				41
# define K_BACKSPACE			42
# define K_TAB				43
# define K_SPACE				44
# define K_MINUS				45
# define K_EQUALS				46
# define K_LEFTBRACKET		47
# define K_RIGHTBRACKET		48
# define K_BACKSLASH			49
# define K_SEMICOLON			51
# define K_APOSTROPHE			52
# define K_GRAVE				53
# define K_COMMA				54
# define K_PERIOD				55
# define K_SLASH				56
# define K_CAPSLOCK			57
# define K_F1					58
# define K_F2					59
# define K_F3					60
# define K_F4					61
# define K_F5					62
# define K_F6					63
# define K_F7					64
# define K_F8					65
# define K_F9					66
# define K_F10				67
# define K_F11				68
# define K_F12				69
# define K_PRINTSCREEN		70
# define K_SCROLLLOCK			71
# define K_PAUSE				72
# define K_INSERT				73
# define K_HOME				74
# define K_PAGEUP				75
# define K_DELETE				76
# define K_END				77
# define K_PAGEDOWN			78
# define K_RIGHT				79
# define K_LEFT				80
# define K_DOWN				81
# define K_UP					82
# define K_NUMLOCKCLEAR		83
# define K_KP_DIVIDE			84
# define K_KP_MULTIPLY		85
# define K_KP_MINUS			86
# define K_KP_PLUS			87
# define K_KP_ENTER			88
# define K_KP_1				89
# define K_KP_2				90
# define K_KP_3				91
# define K_KP_4				92
# define K_KP_5				93
# define K_KP_6				94
# define K_KP_7				95
# define K_KP_8				96
# define K_KP_9				97
# define K_KP_0				98
# define K_KP_PERIOD			99
# define K_LCTRL				224
# define K_LSHIFT				225
# define K_LALT				226
# define K_LGUI				227
# define K_RCTRL				228
# define K_RSHIFT				229
# define K_RALT				230
# define K_RGUI				231
//===================//

//=====Mouse_buttons=====//
# define M_LEFT	        	1
# define M_MIDDLE	    	2
# define M_RIGHT	    	3
# define M_4	        	4
# define M_5	        	5
//Scroll_directions//
# define M_SCROLL_UP		1
# define M_SCROLL_DOWN		2
# define M_SCROLL_RIGHT		3
# define M_SCROLL_LEFT		4
//===================//

//=====Window_events=====//
# define W_CLOSE			0
# define W_MOVED			1
# define W_MINIMIZED		2
# define W_MAXIMIZED		3
# define W_ENTER			4
# define W_FOCUS			5
# define W_LEAVE			6
# define W_UNFOCUS			7
# define W_SIZE_CHANGED	8
# define W_RESIZED			9
# define W_RESTORED		11

#endif
