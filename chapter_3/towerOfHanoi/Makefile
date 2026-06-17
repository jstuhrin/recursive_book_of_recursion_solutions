
NAME = tower

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++23
LDFLAGS =

SRCS = main.cpp towerOfHanoi.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp towerOfHanoi.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

fsan: CXXFLAGS += -fsanitize=address,undefined -g3
fsan: LDFLAGS += -fsanitize=address,undefined
fsan: re

.PHONY: all clean fclean re fsan