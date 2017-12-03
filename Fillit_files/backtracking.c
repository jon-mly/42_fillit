/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:46:04 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/11/24 15:40:54 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

t_solution	**append_solution(t_order *order, t_solution **solutions,
	char **grid)
{
	t_solution	*new_node;

	//if (solutions && *solutions && (*solutions)->square_size <= get_square_size(grid))
		//return (solutions);
	if (!(solutions) || !(new_node = (t_solution *)malloc(sizeof(t_solution))))
		return (NULL);
	new_node->order = order;
	new_node->square_size = get_square_size(grid);
	new_node->next = *solutions;
	*solutions = new_node;
	return (solutions);
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
t_solution		**place_bloc(int index, char ***grid, char ***array,
	t_order *order)
{
	int						bloc_number;
	static t_solution		**solutions = NULL;

	bloc_number = -1;
	if (!(solutions))
	{
		if (!(solutions = (t_solution **)malloc(sizeof(t_solution *))))
			return (NULL);
		*solutions = NULL;
	}
	while (array[++bloc_number])
	{
		if (!elt_in_array(bloc_number, order))
		{
			(order->order)[index] = bloc_number;
			// Si dernier bloc mis en ordre : tente une résolution
			if (index + 1 == order->length && (try_bloc_order(array, *grid, order)))
			{
				solutions = append_solution(orddup(order), solutions, *grid);
				*grid = get_grid((*solutions)->square_size , grid);
			}
			else if (index + 1 < order->length)
				place_bloc(index + 1, grid, array, order);
		}
	}
	(order->order)[index] = -1;
	return (solutions);
}
