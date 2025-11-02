NAME =	rush-02

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c insert_nbr.c utils.c dictionary.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean $(NAME)

.PHONY: clean fclean re
