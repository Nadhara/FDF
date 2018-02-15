/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:30:30 by apruvost          #+#    #+#             */
/*   Updated: 2018/02/15 14:44:58 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"
#include "fdf.h"

int			key_hook(int keycode, void *param)
{
	t_win	*data;

	data = (t_win *)param;
	ft_key_push(keycode, data);
	return ((int)param);
}

void		ft_init(t_win *hey)
{
	hey->nbclicline = 0;
	hey->height = WIN_HEIGHT;
	hey->width = WIN_WIDTH;
	hey->nbline = 0;
	hey->nbrow = 0;
	hey->color = 0x00FFFFFF;
	hey->h = 0.1;
	hey->neg = 1;
	hey->negg = 1;
	hey->palcol = 0;
	hey->tcolor = 1;
}

void		ft_inittwo(t_win *data)
{
	data->len = WIN_WIDTH / (data->nbline + data->nbrow);
	data->originx = data->len * data->nbline;
	data->originy = 200;
	data->colmin[0] = 0x00FFFFFF;
	data->colten[0] = 0x00FF00FF;
	data->coltwen[0] = 0x00FF0000;
	data->colfourty[0] = 0x00FFFF00;
	data->colhund[0] = 0x0000FF00;
	data->colneg[0] = 0x000000FF;
	data->colmin[1] = 0x000000FF;
	data->colten[1] = 0x0000FF00;
	data->coltwen[1] = 0x0000FF00;
	data->colfourty[1] = 0x00FF0000;
	data->colhund[1] = 0x00FFFFFF;
	data->colneg[1] = 0x00A0A0A0;
}

int			main(int argc, char **argv)
{
	t_win	*data;
	int		fd;

	if ((data = (t_win *)malloc(sizeof(t_win))) == NULL)
		exit(0);
	ft_init(data);
	if (((fd = ft_getfile(argc, argv, data)) == -1))
		exit(0);
	ft_create_map(fd, data);
	ft_inittwo(data);
	data->mlxptr = mlx_init();
	data->winptr = mlx_new_window(data->mlxptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
	mlx_hook(data->winptr, 2, (1L << 0), key_hook, (void *)data);
	ft_draw(data);
	mlx_loop(data->mlxptr);
	return (0);
}
