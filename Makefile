NAME = libftprintf.a

SOURCES = ft_putnbr.c ft_putstr.c ft_printf.c ft_putchar.c ft_print_base.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) :
	gcc -c -Wextra -Wall -Werror $(SOURCES)
	ar -rc $(NAME) $(OBJECTS)

clean :
	rm -rf $(OBJECTS)

fclean : clean
		rm -rf $(NAME)

re : fclean all
