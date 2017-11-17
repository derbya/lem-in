#include "lemin.h"

/*link hash table as the nodes are created
 * fix issue with comments after the start/end are found
 * remove debugging*/

void	check_start(char *line, int *check)
{
	check[0] = (ft_strequ("##start", line));
}

void	check_end(char *line, int *check)
{
	check[1] = (ft_strequ("##end", line));
}

void	initialize_check(int *check)
{
	check[0] = 0;
	check[1] = 0;
	check[2] = 0;
}

void	link_index(t_lemin *lemin, int index, char *title)//char *title
{
	t_link	*new;
	t_link	*tmp;

	new = (t_link *)ft_memalloc(sizeof(t_link));
	new->link = index;//new->title = title;
	new->title = title;
	new->next = NULL;
	tmp = lemin->links;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		lemin->links = new;
}

int		linker(char *line, t_lemin **lemin, int found)
{
	char	**ptr;
	int		index;
	int		index2;
	t_lemin	*tmp;

	tmp = *lemin;
//	ft_putstr(line);
//	ft_putstr("\n");
	ptr = (ft_strsplit(line, '-'));
	index = hash_funct(ptr[0], -1, 7);
	index2 = hash_funct(ptr[1], -1, 7);
//	ft_putstr("looking for ");
//	ft_putstr(ptr[0]);
//	ft_putstr(" and ");
//	ft_putstr(ptr[1]);
//	ft_putstr("\n");
	while (tmp)
	{
		if (ft_strequ(tmp->title, ptr[0]))
		{
			link_index(tmp, index2, ptr[1]);//tmp->title
//			ft_putstr("found ");
//			ft_putstr(ptr[0]);
//			ft_putstr("\n");
			found++;
		}
		if (ft_strequ(tmp->title, ptr[1]))
		{
			link_index(tmp, index, ptr[0]);//tmp->title
//			ft_putstr("found ");
//			ft_putstr(ptr[1]);
//			ft_putstr("\n");
			found++;
		}
		if (found == 2)
		{
			ft_putendl(line);
			return (2);
		}
		tmp = tmp->next;
	}
	return (err_handle(E5, 1));
}

int		room_check(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] == '-' || line[0] == 'L')
			return (0);
	return (1);
}

/*can delete the 0 initializations if lines need to be saved*/
int		noder(char *line, t_lemin **lemin, int i, int *check)
{
	t_lemin *new;
	t_lemin *tmp;

	if (!room_check(line))
		return (err_handle(E15, 1));
	new = ft_memalloc(sizeof(t_lemin));
	new->next = NULL;
	new->heuristic = 0;
	new->end_dis = 0;
	new->prev = NULL;
	new->ants = check[2];
	new->ant = 0;
	tmp = *lemin;
	while (line[++i] != ' ')
		;
	new->title = ft_strsub(line, 0, i);
	new->coord.x = ft_atoi(line + i);
	while (line[++i] != ' ')
		;
	new->coord.y = ft_atoi(line + i);
	if (tmp)
		while (tmp->next)
		{
			if (ft_strequ(tmp->next->title, new->title))
				return (1);
			tmp = tmp->next;
		}
	if (check[0] == 2 || check[1] == 2)
	{
		if (check[0] == 2 && check[1] == 2)
			return (err_handle(E4, 0));
		new->coord.z = (check[0] == 2) ? 1 : 2;
	}
	new->links = NULL;
	if (*lemin)
		tmp->next = new;
	else
		*lemin = new;
	ft_putendl(line);
	return (1);
}

void	init_c(int *c)
{
	c[0] = 0;
	c[1] = 0;
}

int		check_format(char *line, t_lemin **lemin, int j, int *check)
{
	int c[2];

	init_c(c);
	if (line[c[1]] == '#')
		return (1);
	while (line[c[1]++])
		if (line[c[1] - 1] == '-')
			c[0]++;
	if (c[0] == 1)
	{
		if (c[1] != 2)
			return (linker(line, lemin, 0));
		else
			return (err_handle(E11, 1));
	}
	init_c(c);
	while (line[c[1]++])
		if (line[c[1] - 1] == ' ')
			c[0]++;
	if (c[0] == 2)
		return (noder(line, lemin, -1, check));
	if (c[0] > 2)
		return (err_handle(E16, 1));
	return (1);
}

/*Might change the way comments are handled, to be ignored immediately*/
/*Will need to check if an end and the start was designated*/

int			comment_pass(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (0);
	else if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
			return (1);
		else
			return (0);
	}
	return (1);
}

void		additional_parsing(int fd, t_lemin **lemin, int *check, int i)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		if (!comment_pass(line))
			continue ;
		if (check[0] == 1 || check[0] == 2)
			if (line[0] != '#')
				check[0]++;
		if (check[1] == 1 || check[1] == 2)
			if (line[0] != '#')
				check[1]++;
		if (!check[0])
			check_start(line, check);
		if (!check[1])
			check_end(line, check);
		if (!(i = check_format(line, lemin, i, check)))
			err_handle(E2, 0);
		free(line);
	}
}

int		check_check(int * check)
{
	if (check[0] != 3 && check[1] != 3)
		return (-1);
	if (check[0] != 3)
		return (err_handle(E11, 1));
	if (check[1] != 3)
		return (err_handle(E12, 1));
	return (1);
}

int		check_ants(char *line, int i)
{
	if (!ft_isdigit(line[0]))
		return (err_handle(E13, 0));
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (-1);
	if (i > 10)
		return (err_handle(E14, 1));
	return (ft_atoi(line));
}

int		parse_data(char *file, t_lemin **lemin)
{
	int		fd;
	char	*line;
	int		check[3];

	initialize_check(check);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (err_handle(E8, 1));
	get_next_line(fd, &line);
	if ((check[2] = check_ants(line, -1)) == -1)
		return (err_handle(E9, 1));
	ft_putendl(line);
	free(line);
	additional_parsing(fd, lemin, check, 0);
	ft_putstr("\n");
	return (check_check(check));
}
