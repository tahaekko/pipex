# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msamhaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 17:31:35 by msamhaou          #+#    #+#              #
#    Updated: 2022/11/03 18:16:42 by msamhaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_bzero.c	ft_isdigit.c	ft_memcpy.c	ft_strlcat.c\
ft_isalnum.c	ft_islpha.c	ft_strlcpy.c\
ft_isascii.c	ft_isprint.c	ft_memset.c	ft_strlen.c	ft_strchr.c\
ft_strrchr.c	ft_strncmp.c	ft_memchr.c	ft_memcmp.c	ft_strnstr.c	ft_atoi.c\
ft_calloc.c 	ft_strdup.c		ft_tolower.c	ft_toupper.c	ft_substr.c	ft_strjoin.c \
ft_strtrim.c	ft_split.c		ft_itoa.c	ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c\
ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_memmove.c

SRC_BONUS = ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
			ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus :	$(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)

%.o : %.c libft.h
	$(CC) $(FLAGS) -c $< 

fclean :
	rm -rf $(OBJ) $(OBJ_BONUS) $(NAME)

clean : 
	rm -rf $(OBJ) $(OBJ_BONUS)
	
re: fclean all
