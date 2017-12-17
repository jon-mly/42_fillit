/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:46:24 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/11/24 12:42:19 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_max_height(char **grid)
{
	int		c;
	int		l;
	int		height;

	c = -1;
	height = 0;
	while (grid[0][++c])
	{
		l = 0;
		while (grid[++l])
			height = (grid[l][c] != '.' && l > height) ? l : height;
	}
	return (height + 1);
}

int		get_max_width(char **grid)
{
	int		c;
	int		l;
	int		width;

	l = -1;
	width = 0;
	while (grid[++l])
	{
		c = -1;
		while (grid[l][++c])
			width = (grid[l][c] != '.' && c > width) ? c : width;
	}
	return (width + 1);
}

int		get_square_size(char **grid)
{
	int		max_height;
	int		max_width;

	max_height = get_max_height(grid);
	max_width = get_max_width(grid);
	return ((max_height > max_width) ? max_height : max_width);
}

int		get_empty_points(char **grid)
{
	int		l;
	int		c;
	int		size;
	int		count;

	l = -1;
	size = ft_strlen(grid[0]);
	count = 0;
	while (grid[++l])
	{
		c = size - 1;
		while (c >= 0 && grid[l][c] == '.')
			c--;
		c++;
		while (--c >= 0)
			count += grid[l][c] == '.';
	}
	return (count);
}
