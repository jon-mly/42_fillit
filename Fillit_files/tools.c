/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:46:43 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/11/24 14:22:46 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Count the number of tetriminos from the chained list in order to malloc
 * a list of char[4][4].
 * At this state, the file is supposed correct through the file. The only error
 * case is an eventual empty file.
 *
 * TODO : handle this case before calling count_blocs.
 */
int		count_blocs(t_filechar **lst)
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
 * Will delete the node given in parameter and will return the one pointed by
 * next.
 * Used in conversion.c
 */
t_filechar	*switch_to_next(t_filechar **lst)
{
	t_filechar	*previous;

	if (lst && *lst)
	{
		previous = *lst;
		*lst = (*lst)->next;
		free(previous);
		previous = NULL;
	}
	return (*lst);
}

/*
 * Alloc a grid "square-shaped" of the length given in parameter.
 * If a pointer is given in second parameter, the grid pointed will be dealloc.
 */
char	**get_grid(int size, char ***previous_grid)
{
	int		i;
	char	**new_grid;
	char	*buffer;

	if (previous_grid)
	{
		i = -1;
		while ((*previous_grid)[++i])
			ft_strdel(&(*previous_grid)[i]);
		free(*previous_grid);
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

void	clear_grid(char **grid)
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
 * Function to know if an int (0 or above, array closed by -1) is in the array
 * given in parameter.
 */
int		elt_in_array(int nb, t_order *order)
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
