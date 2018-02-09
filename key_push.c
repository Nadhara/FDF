/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:01:30 by apruvost          #+#    #+#             */
/*   Updated: 2018/02/09 15:58:27 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx_macos/mlx.h"
#include "./libft/libft.h"

static void		ft_keyfour(int keycode, t_win *data)
{
	if (keycode == KEY_C)
	{
		ft_redraw(data);
		if (data->palcol == 1)
			data->palcol = 0;
		else
			data->palcol = 1;
		ft_draw(data);
	}
}

static void     ft_keythree(int keycode, t_win *data)
{
    switch (keycode)
	{
		case KEY_DOWN :
			ft_redraw(data);
			data->originy += 10;
			ft_draw(data);
			break;
		case KEY_I :
			ft_redraw(data);
			data->neg *= -1;
			ft_draw(data);
			break;
		case KEY_Y :
			ft_redraw(data);
			data->negg *= -1;
			ft_draw(data);
			break;
		default :
			break ;
	}    
}

static void     ft_keytwo(int keycode, t_win *data)
{
    switch (keycode)
	{
		case KEY_PAD_ADD :
			ft_redraw(data);
			data->len++;
			ft_draw(data);
			break;
		case KEY_LEFT :
			ft_redraw(data);
			data->originx -= 10;
			ft_draw(data);
			break;
        case KEY_RIGHT :
            ft_redraw(data);
            data->originx += 10;
            ft_draw(data);
            break;
        case KEY_UP :
            ft_redraw(data);
            data->originy -= 10;
            ft_draw(data);
            break;
		default :
			break ;
	}    
}

void    ft_key_push(int keycode, t_win *data)
{
    switch (keycode)
	{
		case KEY_ESCAPE :
			exit(0);
		case KEY_O :
			ft_redraw(data);
			data->h -= 0.1;
			ft_draw(data);
			break;
		case KEY_P :
			ft_redraw(data);
			data->h += 0.1;
			ft_draw(data);
			break;
        case KEY_PAD_SUB :
            ft_redraw(data);
            data->len--;
            ft_draw(data);
            break;
		default :
			break ;
	}
    ft_keytwo(keycode, data);
    ft_keythree(keycode, data);
	ft_keyfour(keycode, data);
}