NAME	=	ft_printf
CC		=	gcc
OBJ		=	main.c
BONUS	=	
COMP 	=	$(OBJ:.c=.o)
COMP_BONUS	=	$(BONUS:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror
HEADERS	=	includes

all: $(NAME)

$(NAME): $(COMP)
	$(CC) $(NAME) $(COMP)

bonus: $(COMP) $(COMP_BONUS)
	$(CC) $(NAME) $(COMP) $(COMP_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADERS)

clean:
	rm -f $(COMP) $(COMP_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re test
