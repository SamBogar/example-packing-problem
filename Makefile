# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 15:52:30 by sbogar            #+#    #+#              #
#    Updated: 2017/08/10 20:03:06 by sbogar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tetris_solver 

FLAGS = -Wall -Werror -Wextra

FILES = main.c\
		make_board.c\
		pieces.c\
		hash.c\
		solver.c

SRCS = $(addprefix srcs/,$(FILES))

OBJS = $(addprefix objs/,$(FILES:.c=.o))

LIB = libft/libft.a

HEADER = ft_ls.h

all: $(NAME)

$(NAME): objs/ $(LIB) $(OBJS)
	@gcc -o $(NAME) $(FLAGS) $(OBJS) -L./libft/ -lft
	@echo "tetris_solver has been made!"

objs/%.o: src/%.c
	@gcc $(FLAGS) -c $^ -o $@

objs/:
	@mkdir objs

libft/libft.a:
	make -C libft/

clean:
	rm -rf objs
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
