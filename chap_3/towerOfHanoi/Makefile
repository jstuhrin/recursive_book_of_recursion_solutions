
NAME = tower

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++23

SRCS = main.cpp towerOfHanoi.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp towerOfHanoi.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $^ -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re