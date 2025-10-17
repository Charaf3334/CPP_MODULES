CPP       = c++
FLAGS     = -Wall -Wextra -Werror -std=c++98

SRCS      = main.cpp PmergeMe.cpp
OBJS      = $(SRCS:.cpp=.o)
NAME      = PmergeMe

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp PmergeMe.hpp Algos.hpp Algos.tpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all