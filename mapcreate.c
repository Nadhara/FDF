/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcreate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:36:42 by apruvost          #+#    #+#             */
/*   Updated: 2018/02/15 13:51:43 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#include "./libft/libft.h"

void		ft_freestr(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

int			ft_stocknbr(t_win *map, char *line, int i)
{
	char	**str;
	int		j;

	if ((map->mapix[i] = (int *)malloc(sizeof(int) * map->nbrow)) == NULL)
		return (-1);
	if ((str = ft_strsplit(line, ' ')) == NULL)
		return (-1);
	j = 0;
	while (j < map->nbrow)
	{
		if (str[j])
		{
			map->mapix[i][j] = ft_atoi(str[j]);
			j++;
		}
		else
		{
			map->mapix[i][j] = 0;
			j++;
		}
	}
	ft_freestr(str);
	return (1);
}

int			ft_readfile(int fd, t_win *map)
{
	char	*line;
	int		i;

	i = 0;
	while (ft_get_next_line(fd, &line) == 1 && i < map->nbline)
	{
		if ((ft_stocknbr(map, line, i)) == -1)
			exit(0);
		i++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if ((close(fd)) == -1)
		exit(0);
	return (0);
}

void		ft_create_map(int fd, t_win *data)
{
	if ((data->mapix = (int **)malloc(sizeof(int *) * data->nbline)) == NULL)
		exit(0);
	ft_readfile(fd, data);
}
