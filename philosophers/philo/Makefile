#--------------------------------- VARIABLES ---------------------------------#

# Executable (Can be changed).

NAME			= philo

# Color codes (Can be changed).

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# Project (Can be changed).

SRCS_DIR		= src
OBJS_DIR		= obj

# Location of all header files used in the project to avoid
# writing the full path upon include (Can be changed).

INCS_DIR		:= include

# All the subdirectories used in the project
# to organise source files (Can be changed).

OBJS_SUBDIRS	:= core
OBJS_SUBDIRS	+= monitor
OBJS_SUBDIRS	+= philo
OBJS_SUBDIRS	+= utils

#------------------------------------ FILES -----------------------------------#

# Used header at each compilation to check file integrity (Can be changed).

INCS			:= include/ft_core.h
INCS			+= include/ft_enums.h
INCS			+= include/ft_structs.h
INCS			+= include/ft_monitor.h
INCS			+= include/ft_philo.h
INCS			+= include/ft_utils.h

# Source files (Can be changed)

SRCS			:= core/main.c
SRCS			+= core/main_utils.c
SRCS			+= monitor/ft_monitor.c
SRCS			+= monitor/ft_monitor_setup.c
SRCS			+= monitor/ft_monitor_routine.c
SRCS			+= monitor/ft_monitor_property.c
SRCS			+= philo/ft_philo.c
SRCS			+= philo/ft_philo_routine.c
SRCS			+= philo/ft_philo_execute.c
SRCS			+= philo/ft_philo_print.c
SRCS			+= philo/ft_philo_wait.c
SRCS			+= philo/ft_philo_property_0.c
SRCS			+= philo/ft_philo_property_1.c
SRCS			+= philo/ft_philo_shared.c
SRCS			+= philo/ft_philo_utils.c
SRCS			+= utils/ft_isalpha.c
SRCS			+= utils/ft_isdigit.c
SRCS			+= utils/ft_isspace.c
SRCS			+= utils/ft_strlen.c
SRCS			+= utils/ft_bzero.c
SRCS			+= utils/ft_toupper.c
SRCS			+= utils/ft_tolower.c
SRCS			+= utils/ft_strtoi.c
SRCS			+= utils/ft_calloc.c
SRCS			+= utils/ft_putchar_fd.c
SRCS			+= utils/ft_putstr_fd.c
SRCS			+= utils/ft_putendl_fd.c
SRCS			+= utils/ft_putnbr_fd.c
SRCS			+= utils/ft_max.c

#-------------------------------- MISCELANEOUS --------------------------------#

# Some tricks in order to get the makefile doing his job (Can't be changed).

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS			= $(addprefix $(D_OBJS), $(OBJS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(D_OBJS)$(dir))

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled (Can't be changed).

CC				= cc
OBJS			= $(SRCS:.c=.o)

# Compilation flags (Can be changed).

CFLAGS			= $(C_INCS) -Wall -Wextra -Werror

#------------------------------------ RULES -----------------------------------#

# Redefinition of the implicit compilation rule
# to prompt some informations (Can't be changed).

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Implicit make rule simply using dependancies
# to compile our project (Can't be canged).

all: $(OBJS_DIR) $(C_SUBDIRS) $(NAME)

$(NAME): $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Rules used to create folders if they aren't already existing (Can be changed).

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(C_SUBDIRS):
	@mkdir -p $(C_SUBDIRS)

# Deleting all .o files. (Can't be changed).

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) -r $(OBJS_DIR)

# Deleting all executables after cleaning up
# all .o files (Can't be changed).

fclean:
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@make clean
	@$(RM) $(NAME)

# Re-compile everything (Can't be changed).

re:
	@make fclean
	@make all

# Avoid unexpected behaviour when regular files
# get the same name as the following variables (Can be changed).

.PHONY: all clean fclean re
