/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:34:47 by apruvost          #+#    #+#             */
/*   Updated: 2018/02/09 15:59:37 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"

static void     ft_isin(t_win *data, int a)
{
    if (!(data->xi < 0 && data->xf < 0) &&
        !(data->xi > data->width && data->xf > data->width) &&
        !(data->yi < 0 && data->yf < 0) &&
        !(data->yi > data->height && data->yf > data->height))
    {
        if (a == 0)
        ft_line(data, data->color);
        if (a == 1)
        ft_line(data, data->color);
    }
}

static void     ft_drawsquare(t_win *data, int i, int j)
{
    if (i != (data->nbrow - 1))
    {
        data->xi = data->originx + (i * data->len) - ((j * data->len) *
         data->neg);
        data->xf = data->originx + ((i + 1) 
        * data->len) - ((j * data->len) * data->neg);
        data->yi = data->originy + ((j * data->len
        ) * data->negg) - (data->mapix[j][i] * data->h * data->len);
        data->yf = data->originy + ((j * data->len) * 
        data->negg) - (data->mapix[j][i + 1] * data->h * data->len);
        ft_colorx(data, i, j);
        ft_isin(data, 0);
    }
    if (j != (data->nbline - 1))
    {
        data->xi = data->originx + (i * data->len) 
        - ((j * data->len) * data->neg);
        data->xf = data->originx + (i * data->len) -
         (((j + 1) * data->len) * data->neg);
        data->yi = data->originy + ((j * data->len) * data->negg)
         - (data->mapix[j][i] * data->h * data->len);
        data->yf = data->originy + (((j + 1) * data->len) * data->negg) 
        - (data->mapix[j + 1][i] * data->h * data->len);
        ft_colory(data, i, j);
        ft_isin(data, 1);
    }
}

void            ft_draw(t_win *data)
{
    int         j;
    int         i;

    j = 0;
    while (j < data->nbline)
    {
        i = 0;
        while (i < data->nbrow)
        {
            ft_drawsquare(data, i, j);
            i++;
        }
        j++;
    }
    data->color = 0x00FFFFFF;
    ft_ui(data);
}

void	        ft_redraw(t_win *data)
{
	data->re = 1;
	data->color = 0x00000000;
	ft_draw(data);
    ft_ui(data);
	data->re = 0;
	data->color = 0x00FFFFFF;
}