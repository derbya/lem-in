/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:16:38 by ihodge            #+#    #+#             */
/*   Updated: 2017/11/14 14:11:33 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ASTAR_H_
#define	ASTAR_H_
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/inc/libft.h"
#include "lemin.h"

typedef	struct 		s_stack {
	struct s_lemin	*top;
}					t_stack;

typedef struct		s_queue {
	struct s_lemin	*first;
	struct s_lemin	*last;
}					t_queue;

void				add_link_to_queue(t_lemin *prev, t_queue *q,
		t_lemin *start, t_lemin **arr);
int					astar(t_lemin **ar, t_lemin *start, t_lemin *end);
t_lemin 			*astar_calc(t_queue *q, t_lemin **arr, t_lemin *start,
		t_lemin *end);
t_lemin				*astar_init(t_lemin *content);
void				*dequeue(t_queue *queue);
void				enqueue(t_queue *queue, t_lemin *content);
int					enqueue_cont(t_lemin **new, t_lemin **list, t_lemin *content);
t_lemin				*final_path(t_lemin *stack);
void				push(t_stack **stack, t_lemin *content);
t_queue				*q_init(void);
t_stack				*s_init(void);
void				set_distances(t_lemin *prev, t_lemin *node, t_lemin *start);
#endif
