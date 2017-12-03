# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 17:19:32 by jmlynarc          #+#    #+#              #
#    Updated: 2017/11/19 17:19:34 by jmlynarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

FILLIT_REP = Fillit_files/

LIBFT_REP = libft/

# MAKE SURE TO REPLACE THE WILDCARD
SRCS = $(LIBFT_REP)libft.a \
		$(FILLIT_REP)backtracking.c \
		$(FILLIT_REP)conversion.c \
		$(FILLIT_REP)display.c \
		$(FILLIT_REP)file_check.c \
		$(FILLIT_REP)fill.c \
		$(FILLIT_REP)grid_analysis.c \
		$(FILLIT_REP)main.c \
		$(FILLIT_REP)solutions_analysis.c \
		$(FILLIT_REP)tetriminos_check.c \
		$(FILLIT_REP)tetriminos_opti.c \
		$(FILLIT_REP)tools.c \
		$(FILLIT_REP)tools_2.c

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
