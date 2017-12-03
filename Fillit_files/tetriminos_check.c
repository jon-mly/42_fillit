/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:20:15 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/11/19 17:46:13 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		square_is_single(char **tetri, int l, int c)
{
	if (tetri[l][c] == '.')
		return (0);
	if (l > 0 && tetri[l - 1][c] == '#')
		return (0);
	if (l < 3 && tetri[l + 1][c] == '#')
		return (0);
	if (c > 0 && tetri[l][c - 1] == '#')
		return (0);
	if (c < 3 && tetri[l][c + 1] == '#')
		return (0);
	return (1);
}

int		tetrimino_is_correct(char **tetri)
{
	int		l;
	int		c;
	int		squares;

	l = 0;
	squares = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			squares += (tetri[l][c] == '#');
			if (squares > 4 || square_is_single(tetri, l, c))
				return (0);
			c++;
		}
		l++;
	}
	return (squares == 4);
}
