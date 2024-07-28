NAME = megaphone.out

SRCS = megaphone.cpp

OBJS = $(SRCS:.c=.o)

CXX = $(shell which c++ clang++ g++ | head -n 1)

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)