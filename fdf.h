/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:17:52 by apruvost          #+#    #+#             */
/*   Updated: 2018/02/15 14:44:43 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_HEIGHT 800
# define WIN_WIDTH 1000

typedef struct		s_win
{
	void			*mlxptr;
	void			*winptr;
	int				nbclicline;
	int				width;
	int				height;
	int				xi;
	int				xf;
	int				yi;
	int				yf;
	int				nbline;
	int				nbrow;
	int				**mapix;
	int				originx;
	int				originy;
	double			len;
	int				color;
	double			h;
	int				re;
	int				neg;
	int				negg;
	int				colori;
	int				colorf;
	int				colmin[2];
	int				colten[2];
	int				coltwen[2];
	int				colfourty[2];
	int				colhund[2];
	int				colneg[2];
	int				palcol;
	int				tcolor;
}					t_win;

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
}					t_line;

int					ft_getfile(int argc, char **argv, t_win *data);
int					ft_line(t_win *data, int color);
void				ft_create_map(int fd, t_win *data);
void				ft_draw(t_win *data);
void				ft_redraw(t_win *data);
void				ft_ui(t_win *data);
void				ft_key_push(int keycode, t_win *data);
void				ft_colory(t_win *data, int i, int j);
void				ft_colorx(t_win *data, int i, int j);

# define KEY_ESCAPE			53
# define KEY_F1 			122
# define KEY_F2				120
# define KEY_F3				99
# define KEY_F4				118
# define KEY_F5				96
# define KEY_F6				97
# define KEY_F7				98
# define KEY_F8				100
# define KEY_F9				101
# define KEY_F10			109
# define KEY_F11			103
# define KEY_F12			111
# define KEY_F13			105
# define KEY_F14			107
# define KEY_F15			113
# define KEY_F16			106
# define KEY_F17			64
# define KEY_F18			79
# define KEY_F19			80
# define KEY_TILDE			50
# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_4				21
# define KEY_5				23
# define KEY_6				22
# define KEY_7				26
# define KEY_8				28
# define KEY_9				25
# define KEY_0				29
# define KEY_MINUS			27
# define KEY_EQUAL			24
# define KEY_BACKSPACE		51
# define KEY_TAB			48
# define KEY_Q				12
# define KEY_W				13
# define KEY_E				14
# define KEY_R				15
# define KEY_T				17
# define KEY_Y				16
# define KEY_U				32
# define KEY_I				34
# define KEY_O				31
# define KEY_P				35
# define KEY_OPEN_BRACKET	33
# define KEY_OPEN_BRACE		33
# define KEY_CLOSE_BRACKET	30
# define KEY_CLOSE_BRACE	30
# define KEY_BACKSLASH		42
# define KEY_PIPE			42
# define KEY_CAPSLOCK		272
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_F				3
# define KEY_G				5
# define KEY_H				4
# define KEY_J				38
# define KEY_K				40
# define KEY_L				37
# define KEY_COLON			41
# define KEY_SEMI_COLON		41
# define KEY_SIMPLE_QUOTE	39
# define KEY_DOUBLE_QUOTES	39
# define KEY_ENTER			36
# define KEY_SHIFT_LEFT		257
# define KEY_Z				6
# define KEY_X				7
# define KEY_C				8
# define KEY_V				9
# define KEY_B				11
# define KEY_N				45
# define KEY_M				46
# define KEY_LESS_THAN		43
# define KEY_COMMA			43
# define KEY_GREATER_THAN	47
# define KEY_DOT			47
# define KEY_SLASH			44
# define KEY_QUESTION_MARK	44
# define KEY_SHIFT_RIGHT	258
# define KEY_CTRL_LEFT		256
# define KEY_COMMAND_LEFT	259
# define KEY_OPTION_LEFT	261
# define KEY_ALT			261
# define KEY_SPACEBAR		49
# define KEY_COMMAND_RIGHT	260
# define KEY_ALT_GR			262
# define KEY_FN				279
# define KEY_CTRL_RIGHT		269
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DEL			117
# define KEY_HOME			115
# define KEY_END			119
# define KEY_PAGE_UP		116
# define KEY_PAGE_DOWN		121
# define KEY_CLEAR			71
# define KEY_PAD_1			83
# define KEY_PAD_2			84
# define KEY_PAD_3			85
# define KEY_PAD_4			86
# define KEY_PAD_5			87
# define KEY_PAD_6			88
# define KEY_PAD_7			89
# define KEY_PAD_8			91
# define KEY_PAD_9			92
# define KEY_PAD_0			82
# define KEY_PAD_EQUAL		81
# define KEY_PAD_DIVIDE		75
# define KEY_PAD_MULTIPLY	67
# define KEY_PAD_SUB		78
# define KEY_PAD_ADD		69
# define KEY_PAD_ENTER		76
# define KEY_PAD_DOT		65

#endif
