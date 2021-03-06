/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:59:51 by aderby            #+#    #+#             */
/*   Updated: 2017/07/08 14:38:57 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sign(int a)
{
	if (a > 0)
		return (1);
	if (a < 0)
		return (-1);
	return (0);
}
