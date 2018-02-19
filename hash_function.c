/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:46:34 by aderby            #+#    #+#             */
/*   Updated: 2017/11/17 19:46:44 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "astar.h"

int		hash_funct(char *str, int i, int hash)
{
	while (str[++i])
		hash += (int)str[i] * 31 + i;
	return (hash % AR_SIZE);
}

void	initialize_hash_table(t_lemin *lemin, t_lemin **array)
{
	t_lemin	*tmp;
	t_lemin	*collision;
	int		index;

	tmp = lemin;
	while (tmp)
	{
		index = hash_funct(tmp->title, -1, 7);
		if (!array[index])
		{
			array[index] = tmp;
			tmp = tmp->next;
			array[index]->next = NULL;
		}
		else
		{
			collision = array[index];
			while (collision->next)
				collision = collision->next;
			collision->next = tmp;
			tmp = tmp->next;
			collision->next->next = NULL;
		}
	}
}
