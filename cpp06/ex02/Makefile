CC = c++
NAME = serializer
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Base.cpp main.cpp A.cpp B.cpp C.cpp
OBJ = $(SRC:.cpp=.o)
OBJS = $(OBJ:.o=.d)
RM = rm -f
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ) $(NAME)
fclean: clean
	$(RM) $(OBJ) $(OBJS)
re : fclean all
.PHONY: all clean fclean re