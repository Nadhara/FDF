/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:02:41 by apruvost          #+#    #+#             */
/*   Updated: 2018/01/22 15:32:00 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx_macos/mlx.h"
#include "./libft/libft.h"

static void     ft_drawone(t_win *hey, t_line *line, int color)
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
        mlx_pixel_put(hey->mlxptr, hey->winptr, line->x, line->y, color);
        i++;
    }
}

static void     ft_drawtwo(t_win *hey, t_line *line, int color)
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
        mlx_pixel_put(hey->mlxptr, hey->winptr, line->x, line->y, color);
        i++;
    }
}

static int      ft_initline(t_win *hey, int color)
{
    t_line  line;

    line.x = hey->xi;
    line.y = hey->yi;
    line.dx = hey->xf - hey->xi;
    line.dy = hey->yf - hey->yi;
    line.xinc = (line.dx > 0) ? 1 : -1;
    line.yinc = (line.dy > 0) ? 1 : -1;
    line.dx = ft_abs(line.dx);
    line.dy = ft_abs(line.dy);
    mlx_pixel_put(hey->mlxptr, hey->winptr, line.x, line.y, color);
    if (line.dx > line.dy)
        ft_drawone(hey, &line, color);
    else
        ft_drawtwo(hey, &line, color);
    return (0);
}

int             ft_line(t_win *hey, int xl, int yl, int color)
{
    switch (hey->nbclicline)
    {
        case 0 : 
            hey->xi = xl;
            hey->yi = yl;
            hey->nbclicline = 1;
            break;
        case 1 :
            hey->xf = xl;
            hey->yf = yl;
            ft_initline(hey, color);
            hey->nbclicline = 0;
            break;
        default :
            break;
    }
    return (0);
}