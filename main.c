/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:49:05 by aderby            #+#    #+#             */
/*   Updated: 2017/12/02 21:26:36 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "astar.h"

int		err_handle(char *error, int b)
{
	ft_putstr(error);
	if (b)
		exit(1);
	return (0);
}

void	find_start_end(t_lemin *lemin, t_lemin **start, t_lemin **end)
{
	t_lemin *tmp;

	tmp = lemin;
	while (tmp)
	{
		if (tmp->coord.z == 1)
			(*start) = tmp;
		if (tmp->coord.z == 2)
			(*end) = tmp;
		tmp = tmp->next;
	}
}

int		main(void)
{
	t_lemin *lemin;
	t_lemin *end;
	t_lemin *start;
	t_lemin **array;

	lemin = NULL;
	array = (t_lemin **)ft_memalloc(sizeof(t_lemin *) * AR_SIZE);
	if (!parse_data(&lemin))
		return (err_handle(E2, 1));
	find_start_end(lemin, &start, &end);
	if (!start || !end)
		return (err_handle(E6, 1));
	initialize_hash_table(lemin, array);
	astar(array, start, end);
	free_array(array);
	return (0);
}
