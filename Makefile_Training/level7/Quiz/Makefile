NAME := main

SRCS := main.c
OBJS := $(SRCS:.c=.o)

LIB_NAME := ft
LIBFT := lib$(LIB_NAME).a
LIB_SRCS := first.c \
			second.c \
			third.c
LIB_OBJS := $(LIB_SRCS:.c=.o)

AR := ar
ARFLAGS := -rcus
CC := gcc
CFLAGS := -Wall -Wextra -Werror

RM := rm -f

all : $(NAME)

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(LIBFT) $(NAME)

re : fclean all

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT) : $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY : all clean fclean re
