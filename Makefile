NAME = libftprintf.a

#Todo : Add the sources files
#Todo : Add the Objects files
#Todo : Define the $(NAME) variable

all : $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean : clean
		rm -rf $(NAME)

re : fclean all