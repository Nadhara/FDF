/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:08:11 by apruvost          #+#    #+#             */
/*   Updated: 2018/01/31 13:51:30 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./fdf.h"
#include <fcntl.h>

void    ft_rows(int fd, char **line, t_win *data)
{
    while ((ft_get_next_line(fd, line)) == 1)
    {
        data->nbline++;
        ft_strdel(line);
    }
    ft_strdel(line);
}

int     ft_getlinenrow(int *fd, t_win *data)
{
    char    *line;
    char    **test;
    int     i;

    if ((ft_get_next_line(*fd, &line)) == 1)
        data->nbline++;
    if ((test = ft_strsplit(line, ' ')) == NULL)
    {
        ft_strdel(&line);
        return (-1);
    }
    while (test[data->nbrow] != NULL)
        data->nbrow++;
    i = 0;
    while (test[i])
    {
        ft_strdel(&test[i]);
        i++;
    }
    ft_strdel(&line);
    ft_rows(*fd, &line, data);
    free(test);
    test = NULL;
    return (1);
}

int     ft_getfile(int argc, char **argv, t_win *data)
{
    int     fd;

    if (argc == 1)
    {
        ft_putendl("usage : fdf [FILE_PATH]");
        return (-1);
    }
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        ft_putendl("Could not open file.");
        return (-1);
    }
    if ((ft_getlinenrow(&fd, data)) == -1)
        return (-1);
    if (close(fd) == -1)
        return (-1);
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        ft_putendl("Could not open file.");
        return (-1);
    }
    return (fd);
}