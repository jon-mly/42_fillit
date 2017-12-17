/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:19:20 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/11/19 17:19:21 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		structure_is_correct(t_filechar **lst)
{
	t_filechar	*current;
	int			line_count;
	int			char_count;
	int			is_bloc;

	current = *lst;
	line_count = 0;
	char_count = 0;
	is_bloc = 1;
	while (current)
	{
		if (!is_bloc)
		{
			if (current->c != '\n')
				return (0);
			is_bloc = 1;
			line_count = 0;
		}
		else
		{
			if ((char_count == 4 && current->c != '\n') || (char_count < 4 &&
						(current->c != '.' && current->c != '#')))
				return (0);
			line_count += (char_count == 4);
			char_count = (char_count == 4) ? 0 : char_count + 1;
			if (line_count == 4)
				is_bloc = 0;
		}
		current = current->next;
	}
	return (1);
}

int		file_is_correct(t_filechar **lst)
{
	return (chars_are_correct(lst) && structure_is_correct(lst));
}
