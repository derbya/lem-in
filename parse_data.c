/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:26:32 by aderby            #+#    #+#             */
/*   Updated: 2017/12/01 15:50:02 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		parse_data(t_lemin **lemin)
{
	char	*line;
	int		check[3];

	initialize_check(check);
	get_next_line(0, &line);
	if ((check[2] = check_ants(line, -1)) == 0)
	{
		if (line)
			free(line);
		return (err_handle(E9, 1));
	}
	ft_putendl(line);
	free(line);
	addit_parsing(lemin, check, 0);
	ft_putstr("\n");
	return (check_check(check));
}
