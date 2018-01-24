/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:59:38 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/01/24 15:04:11 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
** ====================== INCLUDES =============================================
*/

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

/*
** ====================== DEFINES ==============================================
*/

# define EOF (-1)
# define MAX_GRID_PAR (120)

/*
** ====================== STRUCTURES ===========================================
*/

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

typedef struct	s_ref
{
	int					square_size;
	int					height;
	int					width;
	int					empty_points;
	t_order				*order;
}				t_ref;

/*
** ====================== PROTOTYPES ===========================================
*/

void			exit_with_error(void);
void			display_grid(char **grid);

int				add_tetri_to_grid(char **grid, char ***tetris, int index);
char			**resolve_placements(char ***grid, char ***tetris);

t_ref			**place_bloc(int index, char ***grid, char ***array,
		t_order *order);
int				try_bloc_order(char ***array, char **grid, t_order *order);

void			move_bloc(char **tetri);

t_filechar		**convert_file(int fd);

char			***convert_chained_list(t_filechar **lst);

int				bloc_is_valid(char ***tetris);

t_ref			**create_ref(void);
t_order			*orddup(t_order *order);
int				count_blocs(t_filechar **lst);
t_filechar		*switch_to_next(t_filechar **lst);
char			**get_grid(int size, char **previous_grid);
void			clear_grid(char **grid);
int				elt_in_array(int nb, t_order *order);

int				get_max_height(char **grid);
int				get_max_width(char **grid);
int				get_square_size(char **grid);
int				get_empty_points(char **grid);

int				can_add_tetri(char **grid, char **tetri, int or_l, int or_c);
void			move_bloc_to_grid(char **grid, char **tetri, int or_l,
		int or_c);
void			clear_letter(char letter, char **grid);

int				file_is_correct(t_filechar **lst);

#endif
