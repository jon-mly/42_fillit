#include "fillit.h"

/*
 * The functions below are dedicated to the resolution.
 * To begin a resolution, place_bloc(4) is to be called. It will perform a
 * recursive fill of a t_order object (the same way as for the sudoku, but
 * applied to an int*).
 *
 * TODO: refactor the code to manage a t_ref immediatly instead of a chained
 * list of solutions.
 *
 * WARNING: is not usable as is.
 */

/*
 * Try to add the blocs with the given order (of index).
 * Return 1 if the grid has been filled successfully, 0 otherwise. If 1 is
 * returned, "grid" contais the tetriminos, so the matrice can be analysed.
 * TODO : add order size managment
 */
int				try_bloc_order(char ***array, char **grid, t_order *order)
{
	int		i;
	int		res;

	i = -1;
	clear_grid(grid);
	while (++i < order->length)
	{
		res = add_tetri_to_grid(grid, array[(order->order)[i]]);
		if (!res)
			return (0);
	}
	return (1);
}

static t_ref       *best_solution(char ***grid, t_order *order, t_ref *ref)
{
    int     square_size;
    int     height;
    int     width;
    int     empty_points;

    square_size = get_square_size(*grid);
    height = get_max_height(*grid);
    width = get_max_width(*grid);
    empty_points = get_empty_points(*grid);
    // The following condition is very important for the order of them :
    // it decides if the new solution is better than the ref !
    // Should be carefully reviewed.
    // In order of priority :
    // 1: square size
    // 2: si 1=, max_height
    // 3: si 2=, max_width
    // 4: si 3:=, min empty_points
    return (ref);
}

/*
 * Shall try to fit the newly generated order into the grid, optimize the
 * placement by reducing the grid's size and, if needed, compare the solutions
 * and update the ref.
 * Returns the pointer anyway, updated or not.
 */
static t_ref        **optimize_if_needed(char ***grid, char ***array,
    t_order *new_order, t_ref **p_ref)
{
    // -- int     square_size;

	// No solution found for the current order in the current grid
    if (!(try_bloc_order(array, *grid, new_order)))
        return (p_ref);
	// A solution has been found : should be optimized if possible to fit a narrower square
	// Get current square size
    // -- square_size = get_square_size(grid);
	// Try to fit the blocs into a square with a size reduced by one
    while ((try_bloc_order(array, *grid, order)))
		*grid = get_grid(get_square_size(grid) - 1, grid);
	// The last square size was too small for the blocs to fit :
	// the grid is resized to the smallest size in which the blocs fit.
    *grid = get_grid(++square_size, grid);
    try_bloc_order(array, *grid, order);
    // The new solution shall now be compared to the reference.
    *p_ref = best_solution(grid, new_order, *p_ref);
    return (t_ref);
}

/*
 * Will generate an order of tetriminos recursively, that will be tried by the
 * function above.
 * If the placement is successful in the grid, it will be processed to save a
 * new potential solution.
 * The grid should then be cleaned, and reallocated to a smaller size if
 * needed.
 * "order" is supposed already allocated at the good size, and cleaned.
 */
t_ref		**place_bloc(int index, char ***grid, char ***array,
		t_order *order)
{
	int					bloc_number;
	static t_ref		**p_ref = NULL;

	bloc_number = -1;
	if (!(p_ref) && !(p_ref = create_ref()))
        return (NULL);
	while (array[++bloc_number])
	{
		if (!elt_in_array(bloc_number, order))
		{
			(order->order)[index] = bloc_number;
			if (index + 1 == order->length)
				solutions = optimize_solution(grid, array, order, solutions);
			else if (index + 1 < order->length)
				place_bloc(index + 1, grid, array, order);
		}
	}
	(order->order)[index] = -1;
	return (p_ref);
}
