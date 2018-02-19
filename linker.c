/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:26:32 by aderby            #+#    #+#             */
/*   Updated: 2017/12/02 21:27:33 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			link_index(t_lemin *lemin, int index, char *title)
{
	t_link	*new;
	t_link	*tmp;

	new = (t_link *)ft_memalloc(sizeof(t_link));
	new->link = index;
	new->title = ft_strdup(title);
	new->next = NULL;
	tmp = lemin->links;
	if (tmp)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	else
		lemin->links = new;
	return (1);
}

static int	find_link(char *title, char *link, t_lemin **lemin, int index)
{
	t_lemin	*tmp;

	tmp = *lemin;
	while (tmp)
	{
		if (ft_strequ(tmp->title, title))
			return (link_index(tmp, index, link));
		tmp = tmp->next;
	}
	return (0);
}

int			linker(char *line, t_lemin **lemin, int found)
{
	char	**ptr;
	int		index;
	int		index2;

	ptr = (ft_strsplit(line, '-'));
	index = hash_funct(ptr[0], -1, 7);
	index2 = hash_funct(ptr[1], -1, 7);
	if (find_link(ptr[0], ptr[1], lemin, index2))
		found++;
	if (find_link(ptr[1], ptr[0], lemin, index))
		found++;
	free(ptr[0]);
	free(ptr[1]);
	free(ptr);
	if (found == 2)
	{
		ft_putendl(line);
		return (2);
	}
	return (err_handle(E5, 1));
}
