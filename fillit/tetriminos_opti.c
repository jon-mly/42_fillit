/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_opti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:56:11 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/11/19 17:56:29 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		left_column_empty(char **tetri)
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

int		top_line_empty(char **tetri)
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

void	shift_columns_top(char **tetri)
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

void	shift_lines_left(char **tetri)
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

void	move_tetrimino(char **tetri)
{
	while (left_column_empty(tetri))
		shift_lines_left(tetri);
	while (top_line_empty(tetri))
		shift_columns_top(tetri);
}
