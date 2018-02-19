/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 01:24:02 by aderby            #+#    #+#             */
/*   Updated: 2017/12/02 21:28:11 by ihodge           ###   ########.fr       */
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
# define E18 "Error: The algorithm could not be completed\n"

# define AR_SIZE 524287

typedef struct		s_link
{
	int				link;
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

int					parse_data(t_lemin **lemin);
int					err_handle(char *error, int b);
int					hash_funct(char *str, int i, int hash);
int					room_check(char *line);
int					noder(char *line, t_lemin **lemin, int *check);
int					check_ants(char *line, int i);
int					check_check(int *check);
int					linker(char *line, t_lemin **lemin, int found);
int					comment_pass(char *line);
int					format(char *line, t_lemin **lemin, int *check);
int					link_index(t_lemin *lemin, int index, char *title);
int					hash_funct(char *str, int i, int hash);
void				initialize_hash_table(t_lemin *lemin, t_lemin **array);
void				addit_parsing(t_lemin **lemin, int *check, int i);
void				check_start(char *line, int *check);
void				check_end(char *line, int *check);
void				initialize_check(int *check);
void				init_c(int *c);
void				free_list(t_lemin *list);
void				free_array(t_lemin **array);
void				free_links(t_link *link);
void				free_list_and_links(t_lemin *list);
#endif
