/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:19:25 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/11/24 15:33:37 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
 * stdlib already included
 */


# include <stdio.h>



# include "../libft_files/libft.h"
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

# define EOF (-1)

typedef struct	s_filechar
{
	char				c;
	struct s_filechar	*next;
}				t_filechar;

typedef struct	s_order
{
	int					*order;
	int					length;
}				t_order;

typedef struct	s_solution
{
	t_order				*order;
	int					square_size;
	struct s_solution	*next;
}				t_solution;

typedef struct	s_ref
{
	int					height;
	int					width;
	int					empty_points;
	t_order				*order;
}				t_ref;

void			exit_with_error(void);
int				file_is_correct(t_filechar **lst);
t_filechar		**convert_file(int fd);
int				tetrimino_is_correct(char **tetri);
void			move_tetrimino(char **tetri);
int				add_tetri_to_grid(char **grid, char **tetri);
void			display_grid(char **grid);
int				count_blocs(t_filechar **lst);
t_filechar		*switch_to_next(t_filechar **lst);
char			***convert_chained_list(t_filechar **lst);
char			**get_grid(int size, char ***previous_grid);
int				get_max_height(char **grid);
int				get_max_width(char **grid);
int				get_square_size(char **grid);
int				elt_in_array(int nb, t_order *order);
t_solution		**place_bloc(int index, char ***grid, char ***array, t_order *order);
void			clear_grid(char **grid);
t_order			*orddup(t_order *order);
int				try_bloc_order(char ***array, char **grid, t_order *order);
t_order			*best_order(t_solution **solutions, char **grid, char ***array);
int				get_empty_points(char **grid);
char			get_next_ch(char **grid);
// int				int_tab_size(t_order *tab);
t_order			*best_order_by_sorting(t_solution **solutions, char **grid, char ***array);

#endif
