/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:36:24 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/02 20:49:39 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astar.h"

void	set_distances(t_lemin *prev, t_lemin *node, t_lemin *start)
{
	double	path_dis;
	double	start_dis;

	if (prev->prev)
		path_dis = sqrt(pow(node->coord.x - prev->coord.x, 2) +
				pow(node->coord.y - prev->coord.y, 2));
	start_dis = sqrt(pow(node->coord.x - start->coord.x, 2) +
			pow(node->coord.y - start->coord.y, 2));
	if (prev->prev)
		node->end_dis = path_dis + prev->end_dis;
	node->heuristic = node->end_dis + start_dis;
	node->prev = prev;
}

void	add_link_to_queue(t_lemin *prev, t_queue *q, t_lemin *start,
		t_lemin **arr)
{
	t_lemin	*node;
	t_link	*links;

	links = prev->links;
	while (links)
	{
		node = arr[links->link];
		while (node)
		{
			if (ft_strequ(node->title, links->title))
				break ;
			node = node->next;
		}
		if (!ft_strcmp(start->title, prev->title))
			break ;
		if (prev->prev && ft_strequ(node->title, prev->prev->title))
		{
			links = links->next;
			continue ;
		}
		set_distances(prev, node, start);
		enqueue(q, node);
		links = links->next;
	}
}

t_lemin	*final_path(t_lemin *stack)
{
	t_lemin *head;
	t_lemin	*path;
	t_lemin *previous;

	previous = stack->prev;
	path = astar_init(stack);
	head = path;
	while (stack)
	{
		if (!previous && stack->prev)
			previous = stack->prev;
		if (previous && ft_strequ(stack->title, previous->title))
		{
			path->next = astar_init(stack);
			path = path->next;
			previous = stack->prev;
		}
		stack = stack->next;
	}
	return (head);
}

t_lemin	*astar_calc(t_queue *q, t_lemin **arr, t_lemin *start, t_lemin *end)
{
	t_stack	*stack;
	t_lemin *final_head;
	t_lemin	*prev;

	stack = s_init();
	end->prev = end;
	while (ft_strcmp(start->title, q->first->title))
	{
		prev = q->first;
		push(&stack, dequeue(q));
		if (q->first && ft_strequ(end->title, q->first->title))
			err_handle(E7, 1);
		add_link_to_queue(prev, q, start, arr);
	}
	push(&stack, astar_init(start));
	final_head = final_path(stack->top);
	free_list(stack->top);
	free(stack);
	free_list(q->first);
	free(q);
	return (final_head);
}

int		astar(t_lemin **arr, t_lemin *start, t_lemin *end)
{
	t_queue *q;
	t_lemin *path;

	if (!end->links || !start->links)
		return (err_handle(E7, 1));
	q = q_init();
	enqueue(q, end);
	path = astar_calc(q, arr, start, end);
	ant_traversal(path, start, 0);
	free_list(path);
	return (0);
}
