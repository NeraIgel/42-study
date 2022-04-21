#---------------------------------- VARIABLES ---------------------------------#

# Executable / Library (Can be changed).

FT				= libft.a
NAME			= push_swap
NAME_BONUS		= checker

# Color codes (Can be changed).

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# Libraries (Can be changed).

LFT_DIR			= libft

# Project (Can be changed).

SRCS_DIR		= src
OBJS_DIR		= obj

# Location of all header files used in the project to avoid
# writing the full path upon include (Can be changed).

INCS_DIR		:= include
INCS_DIR		+= libft

# All the subdirectories used in the project
# to organise source files (Can be changed).

OBJS_SUBDIRS	:= core
OBJS_SUBDIRS	+= game
OBJS_SUBDIRS	+= algo
OBJS_SUBDIRS	+= elem
OBJS_SUBDIRS	+= instr
OBJS_SUBDIRS	+= stack
OBJS_SUBDIRS	+= queue
OBJS_SUBDIRS	+= checker

#------------------------------------ FILES -----------------------------------#

# Every libraries needed to compile the project (Can be changed).

LFT				= $(LFT_DIR)/$(FT)

# Used header at each compilation to check file integrity (Can be changed).

INCS			:= include/ft_core.h
INCS			+= include/ft_game.h
INCS			+= include/ft_algo.h
INCS			:= include/ft_elem.h
INCS			+= include/ft_instr.h
INCS			+= include/ft_stack.h
INCS			+= include/ft_queue.h
INCS			+= include/ft_core_bonus.h
INCS			+= include/ft_checker_bonus.h

# Source files (Can be changed)

SRCS			:= core/main.c
SRCS			+= game/ft_game.c
SRCS			+= game/ft_game_setup.c
SRCS			+= game/ft_game_routine.c
SRCS			+= game/ft_game_append_instr.c
SRCS			+= game/ft_game_tuning_instr.c
SRCS			+= game/ft_game_execute_instr.c
SRCS			+= game/ft_game_print.c
SRCS			+= algo/ft_algo_sort.c
SRCS			+= algo/ft_algo_sort_common.c
SRCS			+= algo/ft_algo_sort_greedy.c
SRCS			+= elem/ft_elem.c
SRCS			+= instr/ft_instr_swap.c
SRCS			+= instr/ft_instr_push.c
SRCS			+= instr/ft_instr_rotate.c
SRCS			+= instr/ft_instr_reverse_rotate.c
SRCS			+= stack/ft_stack_0.c
SRCS			+= stack/ft_stack_1.c
SRCS			+= stack/ft_stack_2.c
SRCS			+= stack/ft_stack_3.c
SRCS			+= stack/ft_stack_4.c
SRCS			+= stack/ft_stack_5.c
SRCS			+= queue/ft_queue_0.c
SRCS			+= queue/ft_queue_1.c
SRCS			+= queue/ft_queue_2.c

SRCS_BONUS		:= core/main_bonus.c
SRCS_BONUS		+= checker/ft_checker_bonus.c
SRCS_BONUS		+= checker/ft_checker_print_bonus.c
SRCS_BONUS		+= checker/ft_checker_setup_bonus.c
SRCS_BONUS		+= checker/ft_checker_routine_bonus.c
SRCS_BONUS		+= elem/ft_elem.c
SRCS_BONUS		+= instr/ft_instr_swap.c
SRCS_BONUS		+= instr/ft_instr_push.c
SRCS_BONUS		+= instr/ft_instr_rotate.c
SRCS_BONUS		+= instr/ft_instr_reverse_rotate.c
SRCS_BONUS		+= stack/ft_stack_0.c
SRCS_BONUS		+= stack/ft_stack_1.c
SRCS_BONUS		+= stack/ft_stack_2.c
SRCS_BONUS		+= stack/ft_stack_3.c
SRCS_BONUS		+= stack/ft_stack_4.c
SRCS_BONUS		+= stack/ft_stack_5.c

#-------------------------------- MISCELANEOUS --------------------------------#

# Some tricks in order to get the makefile doing his job (Can't be changed).

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS			= $(addprefix $(D_OBJS), $(OBJS))
C_OBJS_BONUS	= $(addprefix $(D_OBJS), $(OBJS_BONUS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(D_OBJS)$(dir))

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled (Can't be changed).

CC				= gcc
OBJS			= $(SRCS:.c=.o)
OBJS_BONUS		= $(SRCS_BONUS:.c=.o)

# Linked libraries at compile time (Can be changed).

LIBS			:= -L$(LFT_DIR) -lft

# Compilation flags (Can be changed).

CFLAGS			= $(C_INCS) -Wall -Wextra -Werror
#CFLAGS			= $(C_INCS) -Wall -Wextra -Werror -O3

#------------------------------------ RULES -----------------------------------#

# Redefinition of the implicit compilation rule
# to prompt some informations (Can't be changed).

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Implicit make rule simply using dependancies
# to compile our project (Can't be canged).

all: $(OBJS_DIR) $(C_SUBDIRS) $(NAME)

$(NAME): $(LFT) $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

bonus: $(OBJS_DIR) $(C_SUBDIRS) $(NAME_BONUS)

$(NAME_BONUS): $(LFT) $(C_OBJS_BONUS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME_BONUS) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(C_OBJS_BONUS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME_BONUS) successfully compiled   ***\n$(RESET)"

# Libraries installion using their own Makefile (Can be changed).

$(LFT):
	@make -sC $(LFT_DIR) -j

# Rules used to create folders if they aren't already existing (Can be changed).

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(C_SUBDIRS):
	@mkdir -p $(C_SUBDIRS)

# Deleting all .o files. (Can't be changed).

clean:
	@make -sC $(LFT_DIR) clean
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) -r $(OBJS_DIR)

# Deleting all executables and libraries after cleaning up
# all .o files (Can't be changed).

fclean: clean
	@make -sC $(LFT_DIR) fclean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME) $(NAME_BONUS)

# Re-build libs (Can't be changed).

re-libs: $(OBJS_DIR) $(C_SUBDIRS) $(C_OBJS)
	@make -sC $(LFT_DIR) re
	@echo "$(YELLOW)      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Re-compile everything (Can't be changed).

re: fclean all

# Avoid unexpected behaviour when regular files
# get the same name as the following variables (Can be changed).

.PHONY: all clean fclean re bonus
