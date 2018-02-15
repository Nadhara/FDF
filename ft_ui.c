/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:50:01 by apruvost          #+#    #+#             */
/*   Updated: 2018/02/15 14:43:12 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#include "./minilibx_macos/mlx.h"

static void	ft_strput(t_win *data, int x, int y, char *str)
{
	mlx_string_put(data->mlxptr, data->winptr, x, y, data->color, str);
}

void		ft_uitwo(t_win *data)
{
	ft_strput(data, 15, 215, "Press ESC to quit");
	ft_strput(data, 10, 230, "------------------");
	ft_strput(data, 15, 245, "Press Q to center");	
}

void		ft_ui(t_win *data)
{
	data->xi = 200;
	data->xf = 200;
	data->yi = 0;
	data->yf = 300;
	ft_line(data, data->color);
	data->xi = 0;
	data->xf = 200;
	data->yi = 300;
	data->yf = 300;
	ft_line(data, data->color);
	ft_strput(data, 10, 5, "Use arrows to move");
	ft_strput(data, 10, 20, "------------------");
	ft_strput(data, 30, 35, "+(PAD) to zoom");
	ft_strput(data, 20, 50, "-(PAD) to dezoom");
	ft_strput(data, 10, 65, "------------------");
	ft_strput(data, 10, 80, "P to raise height");
	ft_strput(data, 10, 95, "O to lower height");
	ft_strput(data, 10, 110, "------------------");
	ft_strput(data, 7, 125, "I to reverse X axis");
	ft_strput(data, 7, 140, "Y to reverse Y axis");
	ft_strput(data, 10, 155, "------------------");
	ft_strput(data, 15, 170, "C to change color");
	ft_strput(data, 15, 185, "R to toggle color");
	ft_strput(data, 10, 200, "------------------");
	ft_uitwo(data);
}
