/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:37:27 by ihodge            #+#    #+#             */
/*   Updated: 2017/11/14 13:58:42 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astar.h"

t_queue *q_init(void)
{
	t_queue *qu;

	qu = (t_queue*)malloc(sizeof(t_queue));
	qu->first = NULL;
	qu->last = NULL;
	return (qu);
}

int		enqueue_cont(t_lemin **new, t_lemin **list, t_lemin *content)
{
	while ((*list)->next)
	{
		if (content->heuristic < (*list)->next->heuristic)
		{
			(*new) = astar_init(content);
			(*new)->next = (*list)->next;
			(*list)->next = (*new);
			return (1);
		}
		(*list) = (*list)->next;
	}
	if (content->heuristic <= (*list)->heuristic)
	{
		(*new) = astar_init(content);
		(*new)->next = (*list);
		(*list) = (*new);
		return (1);
	}
	return (0);
}

void	enqueue(t_queue *queue, t_lemin *content)
{
	t_lemin *list;
	t_lemin	*new;
	t_lemin *tmp;

	new = NULL;
	if (queue->first)
	{
		if (content->heuristic < queue->first->heuristic)
		{
			new = astar_init(content);
			tmp = queue->first;
			queue->first = new;
			queue->first->next = tmp;
			queue->last = tmp;
			return ;
		}
		list = queue->first;
		if (enqueue_cont(&new, &list, content))
			return ;
		else if (!new && !list->next)
			list->next = astar_init(content);
		queue->last = list->next;
	}
	else
	{
		queue->first = astar_init(content);
		queue->last = queue->first;
	}
}

void	*dequeue(t_queue *queue)
{
	t_lemin *first;

	first = NULL;
	if (queue->first)
	{
		first = queue->first;
		queue->first = queue->first->next;
		first->next = NULL;
		return (first);
	}
	return (NULL);
}
