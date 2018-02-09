/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:45:14 by apruvost          #+#    #+#             */
/*   Updated: 2018/02/09 15:52:58 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#include "minilibx_macos/mlx.h"

int     ft_getcolor(t_win *data, int value)
{
    if (value < 0)
        return (data->colneg[data->palcol]);
    else if (value >= 0 && value < 10)
        return (data->colmin[data->palcol]);
    else if (value >= 10 && value < 20)
        return (data->colten[data->palcol]);
    else if (value >= 20 && value < 40)
        return (data->coltwen[data->palcol]);
    else if (value >= 40 && value < 100)
        return (data->colfourty[data->palcol]);
    else
        return (data->colhund[data->palcol]);
}

void    ft_colory(t_win *data, int i, int j)
{
    if (data->color != 0x00000000)
    {
        data->colori = ft_getcolor(data, data->mapix[j][i]);
        data->colorf = ft_getcolor(data, data->mapix[j + 1][i]);
        if (data->colori == data->colorf)
            data->color = data->colori;
        else
            data->color = data->colori;
    }
}

void    ft_colorx(t_win *data, int i, int j)
{
    if (data->color != 0x00000000)
    {
        data->colori = ft_getcolor(data, data->mapix[j][i]);
        data->colorf = ft_getcolor(data, data->mapix[j][i + 1]);
        if (data->colori == data->colorf)
            data->color = data->colori;
        else
        {
            data->color = data->colorf;
        }
    }
}