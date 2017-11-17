#include "lemin.h"
#include "astar.h"

int		hash_funct(char *str, int i, int hash)
{
	while (str[++i])
		hash += (int)str[i] * 31 + i;
	return (hash % AR_SIZE);
}

int		err_handle(char *error, int b)
{
	ft_putstr(error);
	if (b)
	{
		ft_putstr(USAGE);
		exit(1);
	}
	return (-1);
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
			//ft_putstr("AH\n");
			collision->next = tmp;
			tmp = tmp->next;
			collision->next->next = NULL;
		}
	}
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

int		main(int ac, char **av)
{
	t_lemin *lemin;
	t_lemin *end;
	t_lemin *start;
	t_lemin **array;
	//t_link	*links;
	//t_lemin *tmp;

	lemin = NULL;
	array = (t_lemin **)ft_memalloc(sizeof(t_lemin *) * AR_SIZE);
	if (ac != 2)
		return (err_handle(E1, 1));
	if (!parse_data(av[1], &lemin))
		return (err_handle(E2, 1));
	find_start_end(lemin, &start, &end);
	if (!start || !end)
		return (err_handle(E6, 0));
	initialize_hash_table(lemin, array);
//	ft_putstr("starting astar\n");
	astar(array, start, end);
	//ft_putnbr(lemin->links->link);
	//ft_putstr("\n");
	//ft_putstr("x ");
	//ft_putnbr(array[lemin->links->link]->coord.x);
	//ft_putstr("\n");
	//ft_putstr(array[hash_funct(end->title, -1, 7)]->title);
	///links = array[hash_funct(end->title, -1 , 7)]->links;
	//ft_putstr("\n");
	/*while (links)
	{
		ft_putnbr(links->link);
		ft_putstr("\n");
		links = links->next;
	}
	tmp = lemin;
	while (lemin)
	{
		array[hash_funct(lemin->title, -1, 0)] = lemin;
		ft_putnbr(hash_funct(lemin->title, -1, 0));
		ft_putstr("\n");
		lemin = lemin->next;
	}*/
	//lemin = tmp;
	/*ft_putstr("\n");
	ft_putstr("x ");
	ft_putnbr(array[81]->coord.x);
	ft_putstr("\ny ");
	ft_putnbr(array[81]->coord.y);
	ft_putstr("\nz ");
	ft_putnbr(array[81]->coord.z);
//	ft_putstr(array[lemin->links->link]->title);
	ft_putstr("\nr3 first link is ");
	ft_putnbr(array[9620]->links->link);
	ft_putstr("\nlink 9620 title is ");
	ft_putstr(array[9620]->title);
	ft_putstr("\nr3 second link is ");
	ft_putnbr(array[8070]->links->next->link);
	ft_putstr("\nlink 8008 title is ");
	ft_putstr(array[8008]->title);*/
	//ft_putstr("\n");
}
