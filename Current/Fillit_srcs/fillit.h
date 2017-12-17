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
void	       exit_with_error(void);
void           display_grid(char **grid);

// blocs_opti.c
void	       move_bloc(char **tetri);

// file_conversion.c
t_filechar     **convert_file(int fd);

// chained_list_conversion.c
char	       ***convert_chained_list(t_filechar **lst);

// blocs_validation.c
// ->




#endif
