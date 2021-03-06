/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list_verification.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:34:37 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/01/25 18:28:00 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** These functions review the chained list resulting from the file reading.
*/

int		chars_are_correct(t_filechar **lst)
{
	t_filechar	*current;

	current = *lst;
	while (current)
	{
		if (current->c != '.' && current->c != '#' && current->c != '\n')
			return (0);
		current = current->next;
	}
	return (1);
}

int		perform_is_end(t_filechar *current, int *p_bloc_count, int *p_is_bloc,
		int *p_line_count)
{
	if (!(*p_is_bloc))
	{
		if (*p_bloc_count != 4)
			return (0);
		*p_bloc_count = 0;
		if (current->c != '\n')
			return (0);
		*p_is_bloc = 1;
		*p_line_count = 0;
	}
	return (1);
}

int		perform_is_bloc(t_filechar *current, int *p_bloc_count,
		int *p_char_count, int *p_line_count)
{
	*p_bloc_count += (current->c == '#');
	if ((*p_char_count == 4 && current->c != '\n') || (*p_char_count < 4 &&
						current->c != '.' && current->c != '#'))
		return (0);
	*p_line_count += (*p_char_count == 4);
	*p_char_count = (*p_char_count == 4) ? 0 : (*p_char_count) + 1;
	return (1);
}

int		structure_is_correct(t_filechar *lst)
{
	int			line_count;
	int			char_count;
	int			is_bloc;
	int			bloc_count;

	line_count = 0;
	char_count = 0;
	bloc_count = 0;
	is_bloc = 1;
	while (lst)
	{
		if (!(is_bloc))
		{
			if (!(perform_is_end(lst, &bloc_count, &is_bloc,
							&line_count)))
				return (0);
		}
		else if (!(perform_is_bloc(lst, &bloc_count, &char_count,
				&line_count)))
			return (0);
		is_bloc = (is_bloc && !(line_count == 4 && bloc_count == 4));
		lst = lst->next;
	}
	return (!(is_bloc) || (is_bloc && line_count == 4 && bloc_count == 4));
}

int		file_is_correct(t_filechar **lst)
{
	return (chars_are_correct(lst) && structure_is_correct(*lst));
}
