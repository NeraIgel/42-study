NAME := main

SRC_DIR := ./src/
SRC_NAME := main.c \
			first.c \
			second.c \
			third.c
SRCS := $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR := ./obj/
OBJ_NAME := $(SRC_NAME:.c=.o)
OBJS := $(addprefix $(OBJ_DIR),$(OBJ_NAME))

CC := gcc
CFLAGS := -Wall -Wextra -Werror
INCLUDE := -I ./include

RM := rm -f
RM_DIR := rm -rf

all : $(NAME)

clean :
	$(RM_DIR) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

run : all
	./$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY : all clean fclean re run
