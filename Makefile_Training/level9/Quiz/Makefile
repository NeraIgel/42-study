NAME := main

SRC_DIR := ./src/
SRC_NAME := main.c \
			fourth.c
SRCS := $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR := ./obj/
OBJ_NAME := $(SRC_NAME:.c=.o)
OBJS := $(addprefix $(OBJ_DIR),$(OBJ_NAME))

LIB_DIR := ./lib/
LIB_NAME := ft
LIBFT := $(LIB_DIR)lib$(LIB_NAME).a

CC := gcc
CFLAGS := -Wall -Wextra -Werror
INCLUDE := -I ./include -I ./lib

RM := rm -f
RM_DIR := rm -rf
MAKE := make

all : $(NAME)

clean :
	$(RM_DIR) $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean : clean
	$(RM) $(NAME)

re : fclean all

run : all
	./$(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L$(LIB_DIR) -l$(LIB_NAME) $^ -o $@

$(LIBFT) :
	$(MAKE) -C $(LIB_DIR) all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY : all clean fclean re run
