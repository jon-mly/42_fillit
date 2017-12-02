/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:46:31 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/11/24 15:30:07 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Return the order that produces the minimum height & minimum width.
 */
t_order		*best_order(t_solution **solutions, char **grid, char ***array)
{
	t_ref	*ref;
	int		max_square_size;

	max_square_size = 999;
	if (!(ref = (t_ref *)malloc(sizeof(t_ref))))
		return (NULL);
	ref->height = 999;
	ref->width = 999;
	ref->empty_points = 9999;
	ref->order = NULL;
	if (solutions)
	{
		while (*solutions && (*solutions)->square_size <= max_square_size)
		{
			try_bloc_order(array, grid, (*solutions)->order);
			// display_grid(grid);
			if (get_max_height(grid) <= ref->height &&
				get_max_width(grid) <= ref->width &&
				get_empty_points(grid) <= ref->empty_points)
			{
				ref->height = get_max_height(grid);
				ref->width = get_max_width(grid);
				ref->empty_points = get_empty_points(grid);
				ref->order = orddup((*solutions)->order);
				max_square_size = (*solutions)->square_size;
			}
			*solutions = (*solutions)->next;
		}
	}
	return (ref->order);
}

/*
 * Returns 1 if the candidate is "more ordered" than the reference.
 * The square size is supposed equal to ref's
*/
int 		better_sorted(t_order *ref, t_order *candidate)
{
	int 	i;

	i = -1;
	while (++i < ref->length)
	{
		if ((candidate->order)[i] < (ref->order)[i])
			return (1);
	}
	return (0);
}

t_order		*best_order_by_sorting(t_solution **solutions, char **grid, char ***array)
{
	t_order 	*ref_order;
	int 		max_square_size;
	//int 		i;

	max_square_size = 999;
	ref_order = (*solutions)->order;
	if (solutions) {
		while (*solutions)
		{
			if (try_bloc_order(array, grid, (*solutions)->order))
				ref_order = (*solutions)->order;
			*solutions = (*solutions)->next;
		}

		/*
		while (*solutions && (*solutions)->square_size <= max_square_size)
		{
			i = -1;
			if ((*solutions)->square_size < max_square_size ||
				((*solutions)->square_size < max_square_size &&
				better_sorted(ref_order, (*solutions)->order)))
			{
				ref_order = (*solutions)->order;
				max_square_size = (*solutions)->square_size;
			}
			*solutions = (*solutions)->next;
		}
		*/
	}
	return (ref_order);
}
