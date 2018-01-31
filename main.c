/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:30:30 by apruvost          #+#    #+#             */
/*   Updated: 2018/01/31 14:39:44 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"
#include "fdf.h"

int		mouse_hook(int button, int x, int y, void *hey)
{
	t_win	*test;
	test = (t_win *)hey;
	ft_line(hey, x, y, 0x00FFFFFF);
	return (button);
}

int		key_hook(int keycode, void *param)
{
	switch (keycode)
	{
		case 53 :
			exit(0);
		default :
			break ;
	}
	return ((int)param);
}

void	ft_init(t_win *hey)
{
	hey->nbclicline = 0;
	hey->height = WIN_HEIGHT;
	hey->width = WIN_WIDTH;
	hey->nbline = 0;
	hey->nbrow = 0;
	hey->originx = 300;
	hey->originy = 300;
	hey->len = 10;
}

int		main(int argc, char **argv)
{
	t_win	*data;
	int		fd;

	if ((data = (t_win *)malloc(sizeof(t_win))) == NULL)
		exit(0);
	ft_init(data);
	if (((fd = ft_getfile(argc, argv, data)) == -1))
		exit(0);
	ft_create_map(fd, data);
	data->mlxptr = mlx_init();
	data->winptr = mlx_new_window(data->mlxptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
	mlx_mouse_hook(data->winptr, mouse_hook, (void *)data);
	mlx_key_hook(data->winptr, key_hook, (void *)0);
	ft_draw(data);
	mlx_loop(data->mlxptr);
	return (0);
}