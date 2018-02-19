/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:37:27 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/02 20:12:56 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astar.h"

t_stack	*s_init(void)
{
	t_stack *s;

	s = (t_stack*)malloc(sizeof(t_stack));
	s->top = NULL;
	return (s);
}

void	push(t_stack **stack, t_lemin *content)
{
	if ((*stack)->top)
		content->next = (*stack)->top;
	else
		content->next = NULL;
	(*stack)->top = content;
}
