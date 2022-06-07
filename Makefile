NAME = containers

FLAGS = -Wall -Wextra -Werror -std=gnu++98

SRCS = test/main.cpp
OBJS = main.o

$(NAME): $(OBJS)
	@echo "Tyler is Compiling..."
	@clang++ $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	@echo "Tyler is Creating objects..."
	@clang++ $(FLAGS) -c $(SRCS)

all: $(NAME)

clean:
	@echo "Tyler is Cleaning..."
	@rm -rf $(OBJS) containers
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME)