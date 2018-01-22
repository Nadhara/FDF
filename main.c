/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:30:30 by apruvost          #+#    #+#             */
/*   Updated: 2018/01/22 14:16:57 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"
#include "fdf.h"

int	mouse_hook(int button, int x, int y, void *hey)
{
	t_win	*test;
	test = (t_win *)hey;
	ft_line(hey, x, y, 0x00FFFFFF);
	return (button);
}

int	key_hook(int keycode, void *param)
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

int		main(void)
{
	t_win	*test;

	test = (t_win *)malloc(sizeof(t_win));
	test->nbclicline = 0;
	test->mlxptr = mlx_init();
	test->winptr = mlx_new_window(test->mlxptr, 800, 800, "Poulet braise");
	mlx_mouse_hook(test->winptr, mouse_hook, (void *)test);
	mlx_key_hook(test->winptr, key_hook, (void *)0);
	mlx_loop(test->mlxptr);
	return (0);
}