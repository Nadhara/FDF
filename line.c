/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:02:41 by apruvost          #+#    #+#             */
/*   Updated: 2018/02/01 13:56:52 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx_macos/mlx.h"
#include "./libft/libft.h"

static void     ft_drawone(t_win *data, t_line *line, int color)
{
    int         i;

    i = 1;
    line->cumul = line->dx / 2;
    while (i <= line->dx)
    {
        line->x += line->xinc;
        line->cumul += line->dy;
        if (line->cumul >= line->dx)
        {
            line->cumul -= line->dx;
            line->y += line->yinc;
        }
        mlx_pixel_put(data->mlxptr, data->winptr, line->x, line->y, color);
        i++;
    }
}

static void     ft_drawtwo(t_win *data, t_line *line, int color)
{
    int         i;

    i = 1;
    line->cumul = line->dy / 2;
    while (i <= line->dy)
    {
        line->y += line->yinc;
        line->cumul += line->dx;
        if (line->cumul >= line->dy)
        {
            line->cumul -= line->dy;
            line->x += line->xinc;
        }
        mlx_pixel_put(data->mlxptr, data->winptr, line->x, line->y, color);
        i++;
    }
}

int      ft_line(t_win *data, int color)
{
    t_line  line;

    data->nbclicline = 0;
    line.x = data->xi;
    line.y = data->yi;
    line.dx = data->xf - data->xi;
    line.dy = data->yf - data->yi;
    line.xinc = (line.dx > 0) ? 1 : -1;
    line.yinc = (line.dy > 0) ? 1 : -1;
    line.dx = ft_abs(line.dx);
    line.dy = ft_abs(line.dy);
    mlx_pixel_put(data->mlxptr, data->winptr, line.x, line.y, color);
    if (line.dx > line.dy)
        ft_drawone(data, &line, color);
    else
        ft_drawtwo(data, &line, color);
    return (0);
}

int             ft_manline(t_win *data, int xl, int yl, int color)
{
    switch (data->nbclicline)
    {
        case 0 : 
            data->xi = xl;
            data->yi = yl;
            data->nbclicline = 1;
            break;
        case 1 :
            data->xf = xl;
            data->yf = yl;
            ft_line(data, color);
            break;
        default :
            break;
    }
    return (0);
}