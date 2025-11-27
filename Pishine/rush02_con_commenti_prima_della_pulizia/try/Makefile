NAME =	rush-02

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c insert_nbr.c utils.c ft_strstr.c recursive.c recursive2.c read_dict.c

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
