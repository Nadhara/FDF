/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 03:58:57 by apruvost          #+#    #+#             */
/*   Updated: 2017/11/19 16:37:51 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
		ft_putchar_fd('\n', fd);
	}
}
