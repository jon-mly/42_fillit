/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list_conversion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:33:48 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/01/24 15:07:14 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** These functions are used when :
** the file is checked and validated (meaning : contains no unexpected chars,
** blocs are well structured) : the chained list should be cleared and the grid
** for each bloc should be created and added to an ordered list.  To do so,
** convert_chained_list(1) is called. (Rq : the next step is to validate each
** bloc).
** Warning : when the conversion into a char*** is done, each bloc is
** symbolize by a letter related to its rank (0=A, 1=B, ...) and no more by a
** '#'.
*/

/*
** Get the value pointed by lst, read from there to fill the matrice, and free
** the nodes at the same time.
** When returning, lst points on the first node after the bloc that has been
** converted.
*/

static char		**get_next_bloc(t_filechar **lst, char ch)
{
	int			l;
	int			c;
	char		**bloc;
	char		*buffer;

	if (!(bloc = (char **)malloc(5 * sizeof(char *))) ||
			!(buffer = (char *)malloc(5 * sizeof(char))))
		exit_with_error();
	l = -1;
	while (++l < 4)
	{
		c = 0;
		while (*lst && (*lst)->c != '\n')
		{
			buffer[c++] = ((*lst)->c == '.' ? '.' : ch);
			*lst = switch_to_next(lst);
		}
		buffer[c] = '\0';
		*lst = switch_to_next(lst);
		bloc[l] = ft_strdup(buffer);
	}
	*lst = switch_to_next(lst);
	bloc[l] = NULL;
	return (bloc);
}

/*
** Perform an optimization of bloc position for each char** in the list.
** The function move_bloc(1) is called to move the bloc at its top-left
** position.
*/

static void		optimize_blocs(char ***array)
{
	int		i;

	i = -1;
	while (array[++i])
		move_bloc(array[i]);
}

/*
** Converts the chained list pointed bu "lst" into an array of matrices 5x5,
** cleans properly lst and optimize the placement of the bloc to be at the top
** left of each matrice.
** Returns an object that can be used for the resolution w/ backtracking.
*/

char			***convert_chained_list(t_filechar **lst)
{
	char	***array;
	int		size;
	int		i;

	size = count_blocs(lst);
	if (!(array = (char ***)malloc((size + 1) * sizeof(char **))))
		exit_with_error();
	i = -1;
	while (++i < size)
		array[i] = get_next_bloc(lst, 'A' + i);
	array[i] = NULL;
	optimize_blocs(array);
	return (array);
}
