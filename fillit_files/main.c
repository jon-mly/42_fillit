/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:19:28 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/11/19 17:19:29 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	exit_with_error(void)
{
	ft_putstr_fd("error", 1);
	exit(-1);
}
/*
int		main(int ac, char **av)
{
	int		fd;

	// Only one argument given in parameter
	if (ac != 2)
		exit_with_error();
	// The argument matches a correct file, that has been opened correctly
	if ((fd = open(av[1], O_RDONLY)) < 2)
		exit_with_error();
	// Can begin resolution
	return (0);
}
*/
int main(int ac, char **av)
{
	if (ac != 2)
		exit_with_error();

	int fd = open(av[1], O_RDONLY);
	if (fd < 2)
		exit_with_error();
	t_filechar **lst = convert_file(fd);
	if (!(file_is_correct(lst)))
		exit_with_error();
	int size = count_blocs(lst);
	char ***array = convert_chained_list(lst);
	char ***grid = (char ***)malloc(sizeof(char **));
	*grid = get_grid(size * 4, NULL);
	t_order *order = malloc(size * sizeof(t_order));
	order->length = size;
	order->order = malloc(order->length * sizeof(int *));
	int i = -1;
	while (++i < size)
		(order->order)[i] = -1;
	t_solution **solutions = place_bloc(0, grid, array, order);
//		ft_putendl("HAS ENDED");
//		display_solutions(solutions);

	t_order *b_order =  best_order_by_sorting(solutions, *grid, array); // best_order(solutions, *grid, array);
//		display_order(b_order);
	try_bloc_order(array, *grid, b_order);

//		ft_putendl("BEST ORDER :");
	display_grid(*grid);
	return (0);
}
