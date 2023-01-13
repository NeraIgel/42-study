#--------------------------------- VARIABLES ---------------------------------#

# Executable (Can be changed).

NAME			= brain

# Color codes (Can be changed).

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#------------------------------------ FILES -----------------------------------#

# Source files (Can be changed)

SRCS			:= main.cpp

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled (Can't be changed).

CXX				= c++
OBJS			= $(SRCS:.cpp=.o)

# Compilation flags (Can be changed).

CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

#------------------------------------ RULES -----------------------------------#

# Redefinition of the implicit compilation rule
# to prompt some informations (Can't be changed).

%.o: %.cpp
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Implicit make rule simply using dependancies
# to compile our project (Can't be canged).

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Deleting all .o files. (Can't be changed).

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(OBJS)

# Deleting all executables after cleaning up
# all .o files (Can't be changed).

fclean:
	@make clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)

# Re-compile everything (Can't be changed).

re:
	@make fclean
	@make all

# Avoid unexpected behaviour when regular files
# get the same name as the following variables (Can be changed).

.PHONY: all clean fclean re
