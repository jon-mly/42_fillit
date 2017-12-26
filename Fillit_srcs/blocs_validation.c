#include "fillit.h"
#include <stdio.h>

/*
 * These functions are called when each bloc has to be validated. It is to
 * happen once the chained list has been converted into an array of char** and
 * before beginning the resolution.
 *
 * SEE ALSO : in Legacy code, tetriminos_check.c
 */

static int		case_number_valid(char **tab)
{
	int x;
	int y;
	int count;

	count = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] != '.')
				count++;
			x++;
		}
		y++;
	}
	if (count == 4)
		return (1);
	else
		return (0);
}

static int		tetriminos_valid(char **tab)
{
	int x;
	int y;
	int count;

	count = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] != '.')
			{
				count += (x - 1 >= 0 && tab[y][x - 1] != '.');
				count += (x + 1 < 4 && tab[y][x + 1] != '.');
				count += (y - 1 >= 0 && tab[y - 1][x] != '.');
				count += (y + 1 < 4 && tab[y + 1][x] != '.');
			}
			x++;
		}
		y++;
	}
	if (count >= 6)
		return (1);
	return (0);
}

int		bloc_is_valid(char ***tetris)
{
	int i;

	i = -1;
	while (tetris[++i])
	{
		if (!(case_number_valid(tetris[i])) || !(tetriminos_valid(tetris[i])))
			return (0);
	}
	return (1);
}
