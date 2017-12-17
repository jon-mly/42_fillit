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

}
