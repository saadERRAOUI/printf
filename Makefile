NAME = libftprintf.a

SOURCES = ft_puthex.c ft_putnbr.c ft_putstr.c ft_printf.c ft_putptr.c ft_putchar.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) :
	gcc -c $(SOURCES)
	ar -rc $(NAME) $(OBJECTS)

clean :
	rm -rf $(OBJECTS)

fclean : clean
		rm -rf $(NAME)

re : fclean all
