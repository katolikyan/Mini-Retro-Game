# executable name
NAME := ft_retro

# directories 
SRC_DIR := ./src/
OBJ_DIR	:= ./obj/
HEADERS_DIR := ./includes/

# source files
SRC := main.cpp \
			Bullet.class.cpp \
			Window.class.cpp \
			Menu.class.cpp \
      Object.class.cpp \
      Player.class.cpp \
			Enemy.class.cpp \
			Level.class.cpp \
			Unit.class.cpp \
			Game.class.cpp \

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

# compilation
CC := clang++ 
FLAGS := -Wall -Wextra -Werror -std=c++11
FLAGS += -g -fsanitize=address
HEADERS := -I $(HEADERS_DIR)
LIBS := -lncurses

.PHONY: all clean fclean re

all:	$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(FLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(LIBS) $(OBJ) -o $(NAME) 

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all
