/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:57:44 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/01/24 15:10:27 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	exit_with_error(void)
{
	ft_putstr_fd("error\n", 1);
	exit(-1);
}

void	exit_usage(void)
{
	ft_putstr_fd("usage: fillit file_to_read\n", 1);
	exit(-1);
}

void	display_grid(char **grid)
{
	int		l;

	l = 0;
	while (grid[l])
		ft_putendl(grid[l++]);
}

int		main(int ac, char **av)
{
	int			fd;
//	int			size;
	t_filechar	**lst;
	char		***array;
	char		***grid;

	if (ac != 2)
		exit_usage();
	fd = open(av[1], O_RDONLY);
	if (fd < 2)
		exit_with_error();
	lst = convert_file(fd);
	if ((int)*lst == 0)
		exit_with_error();
	if (!(file_is_correct(lst)) || count_blocs(lst) > 26)
		exit_with_error();
//	size = count_blocs(lst);
	array = convert_chained_list(lst);
	if (!(bloc_is_valid(array)))
		exit_with_error();
	grid = (char ***)malloc(sizeof(char **));
	*grid = get_grid(1, NULL);
	*grid = resolve_placements(grid, array);
	display_grid(*grid);
	return (0);
}
