/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar_struct_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:36:24 by ihodge            #+#    #+#             */
/*   Updated: 2017/11/14 14:20:19 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astar.h"

t_lemin	*astar_init(t_lemin *content)
{
	t_lemin	*new;

	new = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	ft_memcpy(new, content, sizeof(t_lemin));
	new->next = NULL;
	return (new);
}
