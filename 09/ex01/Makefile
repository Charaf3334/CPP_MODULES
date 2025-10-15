CPP       = c++
FLAGS     = -Wall -Wextra -Werror -std=c++98

SRCS      = main.cpp RPN.cpp
OBJS      = $(SRCS:.cpp=.o)
NAME      = RPN

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp RPN.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all