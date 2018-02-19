/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:36:24 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/02 21:25:41 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astar.h"

void	print_format(char *room, int ant)
{
	char *str;

	str = ft_itoa(ant);
	ft_putchar('L');
	ft_putstr(str);
	free(str);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

void	link_start(t_lemin **path)
{
	t_lemin *tmp;
	t_lemin *tmp2;

	tmp = (*path);
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		if (tmp)
			tmp->prev = tmp2;
	}
}

void	finish_path(t_lemin *path)
{
	t_lemin *traverse;
	t_lemin *traverse2;

	traverse2 = path;
	while (traverse2->next)
		traverse2 = traverse2->next;
	while (traverse2->ant != path->ants)
	{
		traverse = traverse2;
		while (traverse != path)
		{
			if (traverse->prev->ant)
			{
				traverse->ant = traverse->prev->ant;
				traverse->prev->ant = 0;
				print_format(traverse->title, traverse->ant);
			}
			traverse = traverse->prev;
		}
		ft_putstr("\n");
	}
}

void	ant_traversal(t_lemin *path, t_lemin *start, int i)
{
	t_lemin	*traverse;
	t_lemin	*traverse2;

	link_start(&path);
	traverse2 = path;
	while (traverse2->next)
		traverse2 = traverse2->next;
	while (++i <= start->ants)
	{
		traverse = traverse2;
		if (!path->ant)
			path->ant = i;
		while (traverse != path)
		{
			if (traverse->prev->ant)
			{
				traverse->ant = traverse->prev->ant;
				traverse->prev->ant = 0;
				print_format(traverse->title, traverse->ant);
			}
			traverse = traverse->prev;
		}
		ft_putstr("\n");
	}
	finish_path(path);
}
