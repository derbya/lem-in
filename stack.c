/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:37:27 by ihodge            #+#    #+#             */
/*   Updated: 2017/11/14 13:58:50 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astar.h"

t_stack *s_init(void)
{
	t_stack *s;

	s = (t_stack*)malloc(sizeof(t_stack));
	s->top = NULL;
	return (s);
}

void	push(t_stack **stack, t_lemin *content)
{
	t_lemin *new;

	new = astar_init(content);
	if ((*stack)->top)
		new->next = (*stack)->top;
	else
		new->next = NULL;
	(*stack)->top = new;
}
