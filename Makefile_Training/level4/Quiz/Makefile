NAME := libft.a

SRCS := first.c \
		second.c \
		third.c
OBJS := first.o \
		second.o \
		third.o

AR := ar
ARFLAGS := -rcus
CC := gcc
CFLAGS := -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $<
