#include "fillit.h"

/*
 * These functions are used to add a bloc to the square grid.
 * When a bloc is passed in parameter of att_tetri_to_grid(2), the possibility
 * to place it is checked, and if possible, it is added to the grid.
 */

static int		c_bloc(char c)
{
	return (c != '.' && c != '\n' && c != '\0');
}

/*
 * return 1 if the tetri can be placed from or_l, or_c in grid, else 0.
 */
static int		can_add_tetri(char **grid, char **tetri, int or_l, int or_c)
{
	int		t_l;
	int		t_c;

	t_l = -1;
	while (grid[or_l + (++t_l)] && t_l < 4)
	{
		t_c = -1;
		while (grid[or_l + t_l][or_c + (++t_c)] && t_c < 4)
		{
			if (c_bloc(tetri[t_l][t_c]) && c_bloc(grid[or_l + t_l][or_c + t_c]))
				return (0);
		}
		if (t_c < 4 && c_bloc(tetri[t_l][t_c]))
			return (0);
	}
	if (!(grid[or_l + t_l]) && t_l < 4)
	{
		t_c = -1;
		while (++t_c < 4)
		{
			if (c_bloc(tetri[t_l][t_c]))
				return (0);
		}
	}
	return (1);
}

static void	    move_bloc_to_grid(char **grid, char **tetri, int or_l, int or_c)
{
	int		t_l;
	int		t_c;

	t_l = -1;
	while (grid[or_l + (++t_l)] && t_l < 4)
	{
		t_c = -1;
		while (grid[or_l + t_l][or_c + (++t_c)] && t_c < 4)
		{
			if (c_bloc(tetri[t_l][t_c]))
				grid[or_l + t_l][or_c + t_c] = tetri[t_l][t_c];
		}
	}
}

/*
 * Return 1 if it has been placed.
 * Return 0 if it couldn't place it.
 */
int		add_tetri_to_grid(char **grid, char **tetri)
{
	int		l;
	int		c;

	l = - 1;
	while (grid[++l])
	{
		c = -1;
		while (grid[l][++c])
		{
			if (can_add_tetri(grid, tetri, l, c))
			{
				move_bloc_to_grid(grid, tetri, l, c);
				return (1);
			}
		}
	}
	return (0);
}
