#include "fillit.h"

/*
 * This method works as follows :
 * - the smallest grid in which the blocs can fit is created
 * - the backtracking is done on the position of each bloc (ordered as given)
 * - if a bloc is placed, the program tries to fit the next one
 * - if the next one can't be placed at all, then it is removed from the grid,
 * and the next position is tested.
 */

// TODO: handle end of tetris
// TODO: func to clear only a given letter
 int		add_tetri_to_grid(char **grid, char ***tetris, int index)
 {
 	int		l;
 	int		c;

 	l = - 1;
    if (!(tetris[index]))
        return (1);
 	while (grid[++l])
 	{
 		c = -1;
 		while (grid[l][++c])
 		{
 			if (can_add_tetri(grid, tetris[index], l, c))
 			{
 				move_bloc_to_grid(grid, tetris[index], l, c);
                if (add_tetri_to_grid(grid, tetris, index + 1))
                    return (1);
                clear_letter('A' + index, grid);
 			}
 		}
 	}
 	return (0);
 }

 char        **resolve_placements(char ***grid, char*** tetris)
 {
     int    size;

     size = 0;
     while (grid[0][size])
        size++;
    size--;
     while (!add_tetri_to_grid(*grid, tetris, 0))
        *grid = get_grid(++size, *grid);
    return (*grid);
 }
