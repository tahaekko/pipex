CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = pipex.c
OBJ = $(SRC:.c=.o)

LIBFT = libft.a
NAME = pipex

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT) : libft/
	make -C libft
	cp libft/$(LIBFT) .

clean :
	rm -rf $(OBJ)
	make clean -C libft

fclean : clean
	rm -rf $(NAME) $(LIBFT)
	make fclean -C libft