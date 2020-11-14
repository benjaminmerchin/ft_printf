NAME	=	libftprintf.a
CC		=	gcc
OBJ		=	main.c
COMP 	=	$(OBJ:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror
HEADERS	=	includes

all: $(NAME)

$(NAME): $(COMP)
	ar rc $(NAME) $(COMP)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADERS)

clean:
	rm -f $(COMP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re test
