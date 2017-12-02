/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:46:47 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/11/24 15:42:15 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

/*
 * Is used when it comes to fill the gid with letters insteand of '#'. Find the
 * "bigger" letter in ASCII value (assuming grid is only filled wth '.' and
 * letters), and returns the next one.
 *
 * FIXME: useless
 *
 */
char	get_next_ch(char **grid)
{
	char	ch;
	int		l;
	int		c;

	ch = 'A';
	l = -1;
	while (grid[++l])
	{
		c = -1;
		while (grid[l][++c])
			ch = (grid[l][c] != '.' && grid[l][c] >= ch) ? grid[l][c] + 1 : ch;
	}
	return (ch);
}

/*
 * special case handling where the tab always ends with -2
 *
 * FIXME: remove
 *
 */
int		int_tab_size(int *tab)
{
	int		i;

	i = 0;
	while (tab[i] != -2)
		i++;
	return (i);
}
