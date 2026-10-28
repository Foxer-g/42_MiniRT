/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethutin- <ethutin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:10:41 by ethutin-          #+#    #+#             */
/*   Updated: 2026/10/28 10:43:12 by ethutin-         ###   ########.fr       */
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
//============================//

//==========Utils==========//
void	update_pos(t_data *data, uint8_t type, int space);
//============================//

//======<key_code>======//
# define MLX_KEY_CROSS  			0
# define MLX_KEY_A					4
# define MLX_KEY_B					5
# define MLX_KEY_C					6
# define MLX_KEY_D					7
# define MLX_KEY_E					8
# define MLX_KEY_F					9
# define MLX_KEY_G					10
# define MLX_KEY_H					11
# define MLX_KEY_I					12
# define MLX_KEY_J					13
# define MLX_KEY_K					14
# define MLX_KEY_L					15
# define MLX_KEY_M					16
# define MLX_KEY_N					17
# define MLX_KEY_O					18
# define MLX_KEY_P					19
# define MLX_KEY_Q					20
# define MLX_KEY_R					21
# define MLX_KEY_S					22
# define MLX_KEY_T					23
# define MLX_KEY_U					24
# define MLX_KEY_V					25
# define MLX_KEY_W					26
# define MLX_KEY_X					27
# define MLX_KEY_Y					28
# define MLX_KEY_Z					29
# define MLX_KEY_1					30
# define MLX_KEY_2					31
# define MLX_KEY_3					32
# define MLX_KEY_4					33
# define MLX_KEY_5					34
# define MLX_KEY_6					35
# define MLX_KEY_7					36
# define MLX_KEY_8					37
# define MLX_KEY_9					38
# define MLX_KEY_0					39
# define MLX_KEY_RETURN				40
# define MLX_KEY_ENTER				40
# define MLX_KEY_ESCAPE				41
# define MLX_KEY_BACKSPACE			42
# define MLX_KEY_TAB				43
# define MLX_KEY_SPACE				44
# define MLX_KEY_MINUS				45
# define MLX_KEY_EQUALS				46
# define MLX_KEY_LEFTBRACKET		47
# define MLX_KEY_RIGHTBRACKET		48
# define MLX_KEY_BACKSLASH			49
# define MLX_KEY_SEMICOLON			51
# define MLX_KEY_APOSTROPHE			52
# define MLX_KEY_GRAVE				53
# define MLX_KEY_COMMA				54
# define MLX_KEY_PERIOD				55
# define MLX_KEY_SLASH				56
# define MLX_KEY_CAPSLOCK			57
# define MLX_KEY_F1					58
# define MLX_KEY_F2					59
# define MLX_KEY_F3					60
# define MLX_KEY_F4					61
# define MLX_KEY_F5					62
# define MLX_KEY_F6					63
# define MLX_KEY_F7					64
# define MLX_KEY_F8					65
# define MLX_KEY_F9					66
# define MLX_KEY_F10				67
# define MLX_KEY_F11				68
# define MLX_KEY_F12				69
# define MLX_KEY_PRINTSCREEN		70
# define MLX_KEY_SCROLLLOCK			71
# define MLX_KEY_PAUSE				72
# define MLX_KEY_INSERT				73
# define MLX_KEY_HOME				74
# define MLX_KEY_PAGEUP				75
# define MLX_KEY_DELETE				76
# define MLX_KEY_END				77
# define MLX_KEY_PAGEDOWN			78
# define MLX_KEY_RIGHT				79
# define MLX_KEY_LEFT				80
# define MLX_KEY_DOWN				81
# define MLX_KEY_UP					82
# define MLX_KEY_NUMLOCKCLEAR		83
# define MLX_KEY_KP_DIVIDE			84
# define MLX_KEY_KP_MULTIPLY		85
# define MLX_KEY_KP_MINUS			86
# define MLX_KEY_KP_PLUS			87
# define MLX_KEY_KP_ENTER			88
# define MLX_KEY_KP_1				89
# define MLX_KEY_KP_2				90
# define MLX_KEY_KP_3				91
# define MLX_KEY_KP_4				92
# define MLX_KEY_KP_5				93
# define MLX_KEY_KP_6				94
# define MLX_KEY_KP_7				95
# define MLX_KEY_KP_8				96
# define MLX_KEY_KP_9				97
# define MLX_KEY_KP_0				98
# define MLX_KEY_KP_PERIOD			99
# define MLX_KEY_LCTRL				224
# define MLX_KEY_LSHIFT				225
# define MLX_KEY_LALT				226
# define MLX_KEY_LGUI				227
# define MLX_KEY_RCTRL				228
# define MLX_KEY_RSHIFT				229
# define MLX_KEY_RALT				230
# define MLX_KEY_RGUI				231
//===================//

//=====Mouse_buttons=====//
# define MLX_MOUSE_LEFT	        	1
# define MLX_MOUSE_MIDDLE	    	2
# define MLX_MOUSE_RIGHT	    	3
# define MLX_MOUSE_4	        	4
# define MLX_MOUSE_5	        	5
//Scroll_directions//
# define MLX_MOUSE_SCROLL_UP		1
# define MLX_MOUSE_SCROLL_DOWN		2
# define MLX_MOUSE_SCROLL_RIGHT		3
# define MLX_MOUSE_SCROLL_LEFT		4
//===================//

//=====Window_events=====//
# define MLX_WINDOW_CLOSE			0
# define MLX_WINDOW_MOVED			1
# define MLX_WINDOW_MINIMIZED		2
# define MLX_WINDOW_MAXIMIZED		3
# define MLX_WINDOW_ENTER			4
# define MLX_WINDOW_FOCUS			5
# define MLX_WINDOW_LEAVE			6
# define MLX_WINDOW_UNFOCUS			7
# define MLX_WINDOW_SIZE_CHANGED	8
# define MLX_WINDOW_RESIZED			9
# define MLX_WINDOW_RESTORED		11

#endif
