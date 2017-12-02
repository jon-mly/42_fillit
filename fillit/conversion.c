/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:19:13 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/11/24 14:34:20 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_filechar		*create_object(char c)
{
	t_filechar		*new_object;

	if (!(new_object = (t_filechar *)malloc(sizeof(t_filechar))))
		return (0);
	new_object->c = c;
	new_object->next = 0;
	return (new_object);
}

t_filechar	**convert_file(int fd)
{
	t_filechar		**begin_list;
	t_filechar		*current_object;
	char			*buffer;

	if (!((buffer = (char *)malloc(sizeof(char))))
			|| !((begin_list = (t_filechar **)malloc(sizeof(t_filechar *)))))
		return (0);
	current_object = 0;
	while (read(fd, buffer, 1) > 0 && *buffer != EOF)
	{
		if (current_object)
		{
			current_object->next = create_object(*buffer);
			current_object = current_object->next;
		}
		else
		{
			*begin_list = create_object(*buffer);
			current_object = *begin_list;
		}
	}
	return (begin_list);
}

/*
 * Get the value pointed by lst, read from there to fill the matrice, and free
 * the nodes at the same time.
 * When returning, lst points on the first node after the bloc that has been
 * converted.
 */
char	**get_next_bloc(t_filechar **lst, char ch)
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

void	optimize_blocs(char ***array)
{
	int		i;

	i = -1;
	while (array[++i])
		move_tetrimino(array[i]);
}

/*
 * Converts the chained list pointed bu "lst" into an array of matrices 5x5,
 * cleans properly lst and optimize the placement of the bloc to be at the top
 * left of each matrice.
 * Returns an object that can be used for the resolution w/ backtracking.
 */
char	***convert_chained_list(t_filechar **lst)
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
