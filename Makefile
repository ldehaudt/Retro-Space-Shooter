NAME = ft_retro

FLAGS = -Wall -Wextra -Werror

SRC = *.cpp

all : $(NAME)

$(NAME) :
	clang++ $(FLAGS) $(SRC) -o $(NAME) -lcurses

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re: fclean all