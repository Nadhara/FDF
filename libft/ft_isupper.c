/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:41:46 by apruvost          #+#    #+#             */
/*   Updated: 2017/11/22 14:50:59 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}