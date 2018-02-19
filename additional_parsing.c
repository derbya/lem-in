/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:26:32 by aderby            #+#    #+#             */
/*   Updated: 2017/12/03 15:39:00 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		format(char *line, t_lemin **lemin, int *check)
{
	int c[2];

	init_c(c);
	if (line[c[1]] == '#')
		return (1);
	while (line[c[1]++])
		if (line[c[1] - 1] == '-')
			c[0]++;
	if (c[0] == 1)
	{
		if (c[1] != 2)
			return (linker(line, lemin, 0));
		else
			return (err_handle(E11, 1));
	}
	init_c(c);
	while (line[c[1]++])
		if (line[c[1] - 1] == ' ')
			c[0]++;
	if (c[0] == 2)
		return (noder(line, lemin, check));
	if (c[0] > 2)
		return (err_handle(E16, 1));
	return (1);
}

int		comment_pass(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (0);
	else if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		{
			ft_putendl(line);
			return (1);
		}
		else
			return (0);
	}
	return (1);
}

void	addit_parsing(t_lemin **lemin, int *check, int i)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (!comment_pass(line))
		{
			free(line);
			continue ;
		}
		if (check[0] == 1 || check[0] == 2)
			if (line[0] != '#')
				check[0]++;
		if (check[1] == 1 || check[1] == 2)
			if (line[0] != '#')
				check[1]++;
		if (!check[0])
			check_start(line, check);
		if (!check[1])
			check_end(line, check);
		if (!(i = format(line, lemin, check)))
			err_handle(E2, 1);
		free(line);
	}
}

int		check_check(int *check)
{
	if (check[0] != 3 && check[1] != 3)
		return (-1);
	if (check[0] != 3)
		return (err_handle(E11, 1));
	if (check[1] != 3)
		return (err_handle(E12, 1));
	return (1);
}

int		check_ants(char *line, int i)
{
	if (!ft_isdigit(line[0]))
		return (err_handle(E13, 1));
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
	if (i > 10)
		return (err_handle(E14, 1));
	return (ft_atoi(line));
}
