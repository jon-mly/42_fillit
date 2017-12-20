#include "fillit.h"

void	exit_with_error(void)
{
	ft_putstr_fd("error", 1);
	exit(-1);
}

void display_grid(char **grid)
{
	int l;

	l = 0;
	while (grid[l])
		ft_putendl(grid[l++]);
}

int     main(int ac, char **av)
{
	if (ac != 2)
		exit_with_error();
	int fd = open(av[1], O_RDONLY);
	if (fd < 2)
		exit_with_error();
	t_filechar **lst = convert_file(fd);
//ft_putendl("11");
//ft_putnbr((int)lst);
//ft_putchar('\n');
//ft_putnbr((int)*lst);
//ft_putchar('\n');
	if ((int)*lst == 0)
		exit_with_error();
	if (!(file_is_correct(lst)))
		exit_with_error();
	//ft_putendl("22");
	int size = count_blocs(lst);
//ft_putendl("33");
	char ***array = convert_chained_list(lst);
//ft_putendl("44");
	if (!(bloc_is_valid(array)))
		exit_with_error();
	//ft_putendl("55");
	char ***grid = (char ***)malloc(sizeof(char **));
	*grid = get_grid(size * 4, NULL);
	t_order *order = malloc(size * sizeof(t_order));
	order->length = size;
	order->order = malloc(order->length * sizeof(int *));
	int i = -1;
	while (++i < size)
		(order->order)[i] = -1;
	t_ref **ref = place_bloc(0, grid, array, order);
//		ft_putendl("HAS ENDED");
//		display_solutions(solutions);
//		display_order(b_order);
	try_bloc_order(array, *grid, (*ref)->order);

//		ft_putendl("BEST ORDER :");
	display_grid(*grid);
	return (0);
}
