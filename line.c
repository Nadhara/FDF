/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:02:41 by apruvost          #+#    #+#             */
/*   Updated: 2018/02/15 14:56:56 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx_macos/mlx.h"
#include "./libft/libft.h"

static int		ft_sub(int min, int max, double value)
{
	int			x;

	x = max - min;
	x *= value;
	return ((min + x));
}

static int		ft_gradcol(int dx, int i, t_win *data)
{
	int			redcol[3];
	int			greencol[3];
	int			bluecol[3];

	redcol[0] = ((data->colori >> 16) & 0xff);
	greencol[0] = ((data->colori >> 8) & 0xff);
	bluecol[0] = ((data->colori) & 0xff);
	redcol[1] = ((data->colorf >> 16) & 0xff);
	greencol[1] = ((data->colorf >> 8) & 0xff);
	bluecol[1] = ((data->colorf) & 0xff);
	redcol[2] = ft_sub(redcol[0], redcol[1], ((double)i / (double)dx));
	greencol[2] = ft_sub(greencol[0], greencol[1], ((double)i / (double)dx));
	bluecol[2] = ft_sub(bluecol[0], bluecol[1], ((double)i / (double)dx));
    return (((redcol[2] & 0xff) << 16) + ((greencol[2] & 0xff) << 8) + (bluecol[2] & 0xff));
}

static void		ft_drawone(t_win *data, t_line *line, int color)
{
	int			i;

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
		if (data->colori != data->colorf && data->tcolor == 1)
			mlx_pixel_put(data->mlxptr, data->winptr, line->x, line->y,
				ft_gradcol(line->dx, i, data));
		else
			mlx_pixel_put(data->mlxptr, data->winptr, line->x, line->y,
				color);
		i++;
	}
}

static void		ft_drawtwo(t_win *data, t_line *line, int color)
{
	int			i;

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
		if (data->colori != data->colorf && data->tcolor == 1)
			mlx_pixel_put(data->mlxptr, data->winptr, line->x, line->y,
				ft_gradcol(line->dy, i, data));
		else
			mlx_pixel_put(data->mlxptr, data->winptr, line->x, line->y,
				color);
		i++;
	}
}

int				ft_line(t_win *data, int color)
{
	t_line		line;

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