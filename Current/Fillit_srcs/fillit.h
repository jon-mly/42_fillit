#ifndef FILLIT_H
# define FILLIT_H

/*
 * ====================== INCLUDES =============================================
 */

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

/*
 * ====================== DEFINES ==============================================
 */

# define EOF (-1)
# define MAX_GRID_PAR (120)

/*
 * ====================== STRUCTURES ===========================================
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
    int                 square_size;
	int					height;
	int					width;
	int					empty_points;
	t_order				*order;
}				t_ref;

/*
 * ====================== PROTOTYPES ===========================================
 */

// main.c
void	       	exit_with_error(void);
void           	display_grid(char **grid);


// backtracking.c
t_ref			**place_bloc(int index, char ***grid, char ***array,
		t_order *order);
int				try_bloc_order(char ***array, char **grid, t_order *order);

// blocs_opti.c
void	       	move_bloc(char **tetri);

// file_conversion.c
t_filechar     	**convert_file(int fd);

// chained_list_conversion.c
char	       	***convert_chained_list(t_filechar **lst);

// blocs_validation.c
// ->

// tools.c
t_ref   		**create_ref(void);
t_order			*orddup(t_order *order);
int				count_blocs(t_filechar **lst);
t_filechar		*switch_to_next(t_filechar **lst);
char			**get_grid(int size, char ***previous_grid);
void			clear_grid(char **grid);
int				elt_in_array(int nb, t_order *order);

// grid_analysis.c
int				get_max_height(char **grid);
int				get_max_width(char **grid);
int				get_square_size(char **grid);
int				get_empty_points(char **grid);

// fill_grid.c
int				add_tetri_to_grid(char **grid, char **tetri);

// chained_list_verification.c
int				file_is_correct(t_filechar **lst);

#endif
