/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:06:53 by apruvost          #+#    #+#             */
/*   Updated: 2018/01/22 15:08:53 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_abs(int nbr)
{
    return ((nbr > 0) ? nbr : (-1 * nbr));
}