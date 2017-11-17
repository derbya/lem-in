/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 01:24:02 by aderby            #+#    #+#             */
/*   Updated: 2017/11/17 15:29:12 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "./libft/inc/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define E1 "Error: to many arguments\n"
# define E2 "Error: the data provided is incorrect\n"
# define E3 "Error: malloc failed but this never happens\n"
# define E4 "Error: The start and end are the same node\n"
# define E5 "Error: The link was made before the node was created\n"
# define E6 "Error: Need both Start and End commands\n"
# define E7 "Error: No valid path\n"
# define E8 "Error: The file given must actually exist\n"
# define E9 "Error: The amount of ants must be given as the first line\n"
# define E10 "Error: Nodes cannot be declared after a link\n"
# define E11 "Error: There must be a start node declared\n"
# define E12 "Error: There must be a unique end node declared\n"
# define E13 "Error: The amount of ants must be positive\n"
# define E14 "Error: The amount of ants must be between 1 and max int\n"
# define E15 "Error: One of the rooms has a '-' or starts with 'L'\n"
# define E16 "Error: There are too many spaces in the room declaration\n"

# define USAGE "Usage: lem-in takes only 1 argument\n./lem-in <file>"
# define AR_SIZE 524287

typedef struct		s_link
{
	int				link;//char *title
	char			*title;
	struct s_link	*next;
}					t_link;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
}					t_coord;

typedef struct		s_lemin
{
	struct s_lemin	*next;
	struct s_lemin	*prev;
	char			*title;
	t_link			*links;
	t_coord			coord;
	double			end_dis;
	double			heuristic;
	int				ants;
	int				ant;
}					t_lemin;

int					parse_data(char *file, t_lemin **lemin);
int					err_handle(char *error, int b);
int					hash_funct(char *str, int i, int hash);
#endif
