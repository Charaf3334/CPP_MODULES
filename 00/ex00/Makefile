CPP       = c++
FLAGS     = -Wall -Wextra -Werror -std=c++98

SRCS      = megaphone.cpp
OBJS      = $(SRCS:.cpp=.o)
NAME      = megaphone

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all