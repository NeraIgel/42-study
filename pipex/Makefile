#---------------------------------- VARIABLES ---------------------------------#

# Executable / Library (Can be changed).

FT				= libft.a
NAME			= pipex

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
OBJS_SUBDIRS	+= file
OBJS_SUBDIRS	+= pipex
OBJS_SUBDIRS	+= process
OBJS_SUBDIRS	+= utils

#------------------------------------ FILES -----------------------------------#

# Every libraries needed to compile the project (Can be changed).

LFT				= $(LFT_DIR)/$(FT)

# Used header at each compilation to check file integrity (Can be changed).

INCS			:= include/ft_core.h
INCS			+= include/ft_pipex.h
INCS			+= include/ft_process.h
INCS			+= include/ft_utils.h
INCS			+= include/ft_core_bonus.h
INCS			+= include/ft_file_bonus.h
INCS			+= include/ft_pipex_bonus.h

# Source files (Can be changed)

SRCS_MANDA		:= core/main.c
SRCS_MANDA		+= pipex/ft_pipex.c
SRCS_MANDA		+= pipex/ft_pipex_setup.c
SRCS_MANDA		+= pipex/ft_pipex_routine.c
SRCS_MANDA		+= process/ft_process.c
SRCS_MANDA		+= utils/ft_dup2.c
SRCS_MANDA		+= utils/ft_execve.c
SRCS_MANDA		+= utils/ft_open.c
SRCS_MANDA		+= utils/ft_waitpid.c

SRCS_BONUS		:= core/main_bonus.c
SRCS_BONUS		+= file/ft_infile_bonus.c
SRCS_BONUS		+= file/ft_outfile_bonus.c
SRCS_BONUS		+= pipex/ft_pipex_bonus.c
SRCS_BONUS		+= pipex/ft_pipex_setup_bonus.c
SRCS_BONUS		+= pipex/ft_pipex_routine_bonus.c
SRCS_BONUS		+= process/ft_process.c
SRCS_BONUS		+= utils/ft_dup2.c
SRCS_BONUS		+= utils/ft_execve.c
SRCS_BONUS		+= utils/ft_open.c
SRCS_BONUS		+= utils/ft_waitpid.c
SRCS_BONUS		+= utils/ft_unlink_bonus.c

#-------------------------------- MISCELANEOUS --------------------------------#

# Some tricks in order to get the makefile doing his job (Can't be changed).

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS_MANDA	= $(addprefix $(D_OBJS), $(OBJS_MANDA))
C_OBJS_BONUS	= $(addprefix $(D_OBJS), $(OBJS_BONUS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(D_OBJS)$(dir))

ifeq ($(BONUS_FLAG),1)
	C_OBJS		= $(C_OBJS_BONUS)
else
	C_OBJS		= $(C_OBJS_MANDA)
endif

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled (Can't be changed).

CC				= gcc
OBJS_MANDA		= $(SRCS_MANDA:.c=.o)
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

bonus:
	@make BONUS_FLAG=1

$(NAME): $(LFT) $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

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
	@$(RM) $(NAME)

# Re-build libs (Can't be changed).

re-libs: $(OBJS_DIR) $(C_SUBDIRS) $(C_OBJS)
	@make -sC $(LFT_DIR) re
	@echo "$(YELLOW)      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Re-compile everything (Can't be changed).

re:
	@make fclean
	@make all

# Avoid unexpected behaviour when regular files
# get the same name as the following variables (Can be changed).

.PHONY: all clean fclean re bonus
