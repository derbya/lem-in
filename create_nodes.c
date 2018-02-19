/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:26:32 by aderby            #+#    #+#             */
/*   Updated: 2017/11/21 01:45:40 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin		*init_new(int *check, char *line, int i)
{
	t_lemin *new;

	new = ft_memalloc(sizeof(t_lemin));
	new->next = NULL;
	new->prev = NULL;
	new->heuristic = 0;
	new->end_dis = 0;
	new->ant = 0;
	new->ants = check[2];
	while (line[++i] != ' ')
		;
	new->title = ft_strsub(line, 0, i);
	new->coord.x = ft_atoi(line + i);
	while (line[++i] != ' ')
		;
	new->coord.y = ft_atoi(line + i);
	return (new);
}

static int	helper(char *line)
{
	ft_putendl(line);
	return (1);
}

int			noder(char *line, t_lemin **lemin, int *check)
{
	t_lemin *new;
	t_lemin *tmp;

	if (!room_check(line))
		return (err_handle(E15, 1));
	new = init_new(check, line, -1);
	tmp = *lemin;
	if (tmp)
		while (tmp->next)
		{
			if (ft_strequ(tmp->next->title, new->title))
				return (1);
			tmp = tmp->next;
		}
	if ((check[0] == 2 || check[1] == 2) && ((new->links = NULL) == NULL))
	{
		if (check[0] == 2 && check[1] == 2)
			return (err_handle(E4, 1));
		new->coord.z = (check[0] == 2) ? 1 : 2;
	}
	(*lemin) ? (tmp->next = new)
		: (*lemin = new);
	return (helper(line));
}
