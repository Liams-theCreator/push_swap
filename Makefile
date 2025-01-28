NAME = push_swap
CC = cc
FLAGS = -Werror -Wextra -Wall
SRC = input.c operations.c pushswap.c strfunc.c strfunc2.c strfunc3.c listfunc.c error_handling.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $<

.PHONY: clean fclean all re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
