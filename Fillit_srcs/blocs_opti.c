/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocs_opti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:32:07 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/01/24 15:05:19 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** The functions below are dedicated to move the tetriminos at the top left
** position.
** move_bloc(1) should be called once the blocs have been converted into a list
** of char**, before or after they have been verified and valdated
*/

static int		left_column_empty(char **tetri)
{
	int		l;

	l = -1;
	while (++l < 4)
	{
		if (tetri[l][0] && tetri[l][0] != '.')
			return (0);
	}
	return (1);
}

static int		top_line_empty(char **tetri)
{
	int		c;

	c = -1;
	while (++c < 4)
	{
		if (tetri[0][c] && tetri[0][c] != '.')
			return (0);
	}
	return (1);
}

static void		shift_columns_top(char **tetri)
{
	int		c;
	int		l;

	c = -1;
	while (++c < 4)
	{
		l = 0;
		while (++l < 4)
			tetri[l - 1][c] = tetri[l][c];
		tetri[3][c] = '.';
	}
}

static void		shift_lines_left(char **tetri)
{
	int		c;
	int		l;

	l = -1;
	while (++l < 4)
	{
		c = 0;
		while (++c < 4)
			tetri[l][c - 1] = tetri[l][c];
		tetri[l][3] = '.';
	}
}

void			move_bloc(char **tetri)
{
	while (left_column_empty(tetri))
		shift_lines_left(tetri);
	while (top_line_empty(tetri))
		shift_columns_top(tetri);
}
