/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:58:13 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/01/24 15:10:56 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This file groups functions that do not belong to any other file.
*/

t_ref		**create_ref(void)
{
	t_ref	**new_ref;

	if (!(new_ref = (t_ref**)malloc(sizeof(t_ref*))) ||
			!(*new_ref = (t_ref*)malloc(sizeof(t_ref))))
		return (NULL);
	(*new_ref)->square_size = MAX_GRID_PAR;
	(*new_ref)->height = MAX_GRID_PAR;
	(*new_ref)->width = MAX_GRID_PAR;
	(*new_ref)->empty_points = MAX_GRID_PAR * MAX_GRID_PAR;
	(*new_ref)->order = NULL;
	return (new_ref);
}

t_order		*orddup(t_order *order)
{
	t_order		*dest;
	int			i;

	if (!(order) || !(dest = (t_order *)malloc(sizeof(t_order))) ||
			!(dest->order = (int *)malloc(order->length * sizeof(int))))
		return (NULL);
	i = -1;
	dest->length = order->length;
	while (++i < order->length)
		(dest->order)[i] = (order->order)[i];
	return (dest);
}

int			count_blocs(t_filechar **lst)
{
	t_filechar	*current;
	size_t		size;

	current = *lst;
	if (current->c == '#' || current->c == '.')
		size = 1;
	else
		return (0);
	while (current)
	{
		if (current->next && current->c == '\n' && (current->next)->c == '\n')
			size++;
		current = current->next;
	}
	return (size);
}

/*
** Alloc a grid "square-shaped" of the length given in parameter.
** If a pointer is given in second parameter, the grid pointed will be dealloc.
*/

char		**get_grid(int size, char **previous_grid)
{
	int		i;
	char	**new_grid;
	char	*buffer;

	if (previous_grid)
	{
		i = -1;
		while (previous_grid[++i])
			ft_strdel(&(previous_grid[i]));
		free(previous_grid);
	}
	if (!(new_grid = (char **)malloc((size + 1) * sizeof(char *))) ||
			!(buffer = ft_strnew(size)))
		return (NULL);
	i = -1;
	ft_memset(buffer, '.', size);
	while (++i < size)
		new_grid[i] = ft_strdup(buffer);
	ft_strdel(&buffer);
	new_grid[i] = NULL;
	return (new_grid);
}

void		clear_grid(char **grid)
{
	int		l;
	int		c;

	l = -1;
	while (grid[++l])
	{
		c = -1;
		while (grid[l][++c])
			grid[l][c] = '.';
	}
}

/*
** Function to know if an int (0 or above, array closed by -1) is in the array
** given in parameter.
*/

int			elt_in_array(int nb, t_order *order)
{
	int		i;

	i = -1;
	while (++i < order->length)
	{
		if ((order->order)[i] == nb)
			return (1);
	}
	return (0);
}
