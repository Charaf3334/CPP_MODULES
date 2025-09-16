CPP       = c++
FLAGS     = -Wall -Wextra -Werror -std=c++98

SRCS      = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS      = $(SRCS:.cpp=.o)
NAME      = Materia

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.cpp MateriaSource.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all