/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:26:19 by aderby            #+#    #+#             */
/*   Updated: 2017/11/17 19:26:27 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_start(char *line, int *check)
{
	check[0] = (ft_strequ("##start", line));
}

void	check_end(char *line, int *check)
{
	check[1] = (ft_strequ("##end", line));
}

void	initialize_check(int *check)
{
	check[0] = 0;
	check[1] = 0;
	check[2] = 0;
}

int		room_check(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] == '-' || line[0] == 'L')
			return (0);
	return (1);
}

void	init_c(int *c)
{
	c[0] = 0;
	c[1] = 0;
}
