/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:17:52 by apruvost          #+#    #+#             */
/*   Updated: 2018/01/22 15:22:01 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef		struct s_win
{
	void	*mlxptr;
	void	*winptr;
	int		nbclicline;
	int		xi;
	int		xf;
	int		yi;
	int		yf;
}			t_win;

typedef		struct s_line
{
	int		dx;
	int		dy;
	int		xinc;
	int		yinc;
	int		cumul;
	int		x;
	int		y;
}			t_line;

int			ft_line(t_win *hey, int x, int y, int color);

#endif
