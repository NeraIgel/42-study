NAME := libftprintf.a

BASIC_SRC_DIR := ./src/
BASIC_SRC_NAME := ft_printf.c \
				  ft_vfprintf.c \
				  ft_specifier.c \
				  ft_formatter.c \
				  ft_output_c.c \
				  ft_output_s.c \
				  ft_output_p.c \
				  ft_output_i.c \
				  ft_output_ui.c \
				  ft_output_x.c \
				  ft_output_ux.c \
				  ft_utils.c
BASIC_SRCS := $(addprefix $(BASIC_SRC_DIR),$(BASIC_SRC_NAME))

BONUS_SRC_DIR := ./bonus/
BONUS_SRC_NAME := ft_printf_bonus.c \
				  ft_vfprintf_bonus.c \
				  ft_specifier_bonus.c \
				  ft_formatter_bonus.c \
				  ft_output_c_bonus.c \
				  ft_output_s_bonus.c \
				  ft_output_p_bonus.c \
				  ft_output_i_bonus.c \
				  ft_output_ui_bonus.c \
				  ft_output_x_bonus.c \
				  ft_output_ux_bonus.c \
				  ft_output_percent_bonus.c \
				  ft_output_utils_bonus.c \
				  ft_utils_bonus.c
BONUS_SRCS := $(addprefix $(BONUS_SRC_DIR),$(BONUS_SRC_NAME))

OBJ_DIR := ./obj/
BASIC_OBJ_NAME := $(BASIC_SRC_NAME:.c=.o)
BONUS_OBJ_NAME := $(BONUS_SRC_NAME:.c=.o)
BASIC_OBJS := $(addprefix $(OBJ_DIR),$(BASIC_OBJ_NAME))
BONUS_OBJS := $(addprefix $(OBJ_DIR),$(BONUS_OBJ_NAME))

INC_DIR := ./include/

LIB_NAME := ft
LIB_DIR := ./lib$(LIB_NAME)/
LIBFT := $(LIB_DIR)lib$(LIB_NAME).a

AR := ar
ARFLAGS := -rcus
CC := gcc
CFLAGS := -Wall -Wextra -Werror

ifeq ($(BONUS_FLAG),1)
	OBJS := $(BONUS_OBJS)
	SRC_DIR := $(BONUS_SRC_DIR)
	INCLUDE := -I $(LIB_DIR)
else
	OBJS := $(BASIC_OBJS)
	SRC_DIR := $(BASIC_SRC_DIR)
	INCLUDE := -I $(INC_DIR) -I $(LIB_DIR)
endif

CP := cp
RM := rm -f
RM_DIR := rm -rf
MK_DIR := @mkdir -p
MAKE := @make

all : $(NAME)

clean :
	$(MAKE) -C $(LIB_DIR) clean
	$(RM_DIR) $(OBJ_DIR)

fclean : clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re : fclean all

bonus :
	$(MAKE) BONUS_FLAG=1

$(NAME) : $(LIBFT) $(OBJS)
	$(CP) $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $@ $?

$(LIBFT) :
	$(MAKE) -C $(LIB_DIR) all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(MK_DIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY : all clean fclean re bonus
