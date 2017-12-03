#include "fillit.h"

void display_grid(char **grid)
{
	int l;

	l = 0;
	while (grid[l])
		ft_putendl(grid[l++]);
}
