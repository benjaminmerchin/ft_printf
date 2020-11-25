NAME	=	libftprintf.a
CC		=	gcc
OBJ		=	ft_printf.c hex.c itoa.c string.c int.c pointer.c utils.c
COMP 	=	$(OBJ:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(COMP)
	ar rc $(NAME) $(COMP)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(COMP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re test
