CPP       = c++
FLAGS     = -Wall -Wextra -Werror -std=c++98

SRCS      = main.cpp Base.cpp A.cpp B.cpp C.cpp functions.cpp
OBJS      = $(SRCS:.cpp=.o)
NAME      = a.out

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Base.hpp A.hpp B.hpp C.hpp functions.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all