NAME := libft.a

SRCS := ft_isdigit.c \
   		ft_strlen.c \
		ft_bzero.c \
		ft_strchr.c
OBJS := $(SRCS:.c=.o)

AR := ar
ARFLAGS := -rcus
CC := gcc
CFLAGS := -Wall -Wextra -Werror

RM := rm -f
MAKE := make

all : $(NAME)

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY : all clean fclean re
