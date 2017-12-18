NAME = fillit

FLAGS = -Wall -Werror -Wextra

FILLIT_REP = Fillit_srcs/

LIBFT_REP = libft/

# MAKE SURE TO REPLACE THE WILDCARD
SRCS = $(LIBFT_REP)libft.a \
		$(FILLIT_REP)main.c \
		$(FILLIT_REP)backtracking.c \
		$(FILLIT_REP)blocs_opti.c \
		$(FILLIT_REP)blocs_validation.c \
		$(FILLIT_REP)chained_list_conversion.c \
		$(FILLIT_REP)file_conversion.c \
		$(FILLIT_REP)grid_analysis.c \
		$(FILLIT_REP)tools.c \
		$(FILLIT_REP)fill_grid.c \
		$(FILLIT_REP)chained_list_verification.c \

# MAKE SURE TO REPLACE THE WILDCARD
O_FILES = $(SRCS:.c=.o)

INCLUDES = includes/

$(NAME):
	cd $(LIBFT_REP) && make
	gcc $(FLAGS) $(SRCS) -I $(INCLUDES) -o $(NAME)

all: $(NAME)

clean:
	cd $(LIBFT_REP) && make clean
	rm -f $(O_FILES)

fclean: clean
	cd $(LIBFT_REP) && make fclean
	#rm -f $(NAME)

re: fclean all
