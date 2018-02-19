/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:49:05 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/02 21:02:43 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "astar.h"

void	free_links(t_link *link)
{
	t_link *tmp;

	tmp = link;
	while (link)
	{
		link = link->next;
		free(tmp->title);
		free(tmp);
		tmp = link;
	}
}

void	free_list_and_links(t_lemin *list)
{
	t_lemin	*tmp;

	tmp = list;
	while (list)
	{
		list = list->next;
		free(tmp->title);
		if (tmp->links && tmp->links->title)
			free_links(tmp->links);
		free(tmp);
		tmp = list;
	}
}

void	free_list(t_lemin *list)
{
	t_lemin	*tmp;

	tmp = list;
	while (list)
	{
		list = list->next;
		if (tmp)
			free(tmp);
		tmp = list;
	}
}

void	free_array(t_lemin **array)
{
	int i;

	i = -1;
	while (++i < AR_SIZE)
		if (array[i])
			free_list_and_links(array[i]);
	free(array);
}
