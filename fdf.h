/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:17:52 by apruvost          #+#    #+#             */
/*   Updated: 2018/01/31 14:39:32 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_HEIGHT 800
# define WIN_WIDTH 1000

typedef		struct s_win
{
	void	*mlxptr;
	void	*winptr;
	int		nbclicline;
	int		width;
	int		height;
	int		xi;
	int		xf;
	int		yi;
	int		yf;
	int		nbline;
	int		nbrow;
	int		**mapix;
	int		originx;
	int		originy;
	int		len;
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

int			ft_getfile(int argc, char **argv,t_win *data);
int			ft_line(t_win *data, int x, int y, int color);
void		ft_create_map(int fd, t_win *data);
void		ft_draw(t_win data);

#endif
