# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 14:20:14 by aderby            #+#    #+#              #
#    Updated: 2017/11/14 14:31:47 by ihodge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

C_FIL = main.c parse_data.c algo.c queue.c stack.c astar_struct_init.c

O_FIL = ${C_FIL:.c=.o}
O_LOC = obj

GCC_FLAGS = gcc -Wall -Wextra -Werror -g

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(O_FIL)
		cd libft && make re
		$(GCC_FLAGS) $(LIB) $(O_FIL) -o $(NAME)

%.o: %.c
	$(GCC_FLAGS) -c $< -o $@

clean:
		cd libft && make clean
		saferm $(O_FIL)

fclean: clean
		cd libft && make fclean
		saferm -f $(NAME)

re: fclean all
