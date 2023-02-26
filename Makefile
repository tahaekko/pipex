# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 11:46:42 by msamhaou          #+#    #+#              #
#    Updated: 2023/02/26 22:16:20 by msamhaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = pipex.c pipex_utils.c	pipex_utils_plus.c
OBJ = $(SRC:.c=.o)
LIBFT = libft.a
NAME = pipex

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
%.o : %.c pipex.h
	$(CC) $(FLAGS) -c $<
$(LIBFT) : libft/
	make -C libft
	cp libft/libft.a .
clean : 
	rm -rf $(OBJ)
	make clean -C libft
fclean : clean
	rm -rf $(NAME) $(LIBFT)
	make fclean -C libft