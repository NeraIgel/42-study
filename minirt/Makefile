#--------------------------------- VARIABLES ---------------------------------#

# Executable / Library (Can be changed).

FT				= libft.a
MLX				= libmlx.dylib
NAME			= miniRT

# Color codes (Can be changed).

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# Libraries (Can be changed).

LFT_DIR			= libft
LMLX_DIR		= libmlx
#LMLX_DIR		= libmlx2

# Project (Can be changed).

SRCS_DIR		= src
OBJS_DIR		= obj

# Location of all header files used in the project to avoid
# writing the full path upon include (Can be changed).

INCS_DIR		:= include
INCS_DIR		+= libft
INCS_DIR		+= libmlx
#INCS_DIR		+= libmlx2

# All the subdirectories used in the project
# to organise source files (Can be changed).

OBJS_SUBDIRS	:= core
OBJS_SUBDIRS	+= deque
OBJS_SUBDIRS	+= minirt
OBJS_SUBDIRS	+= graphic
OBJS_SUBDIRS	+= object
OBJS_SUBDIRS	+= scene
OBJS_SUBDIRS	+= ray
OBJS_SUBDIRS	+= vector
OBJS_SUBDIRS	+= utils

#------------------------------------ FILES -----------------------------------#

# Every libraries needed to compile the project (Can be changed).

LFT				= $(LFT_DIR)/$(FT)
LMLX			= $(LMLX_DIR)/$(MLX)

# Used header at each compilation to check file integrity (Can be changed).

INCS			:= include/ft_core.h
INCS			+= include/ft_deque.h
INCS			+= include/ft_enums.h
INCS			+= include/ft_minirt.h
INCS			+= include/ft_graphic.h
INCS			+= include/ft_structs.h
INCS			+= include/ft_key_mac.h
INCS			+= include/ft_mlx_events.h
INCS			+= include/ft_object.h
INCS			+= include/ft_sphere.h
INCS			+= include/ft_plane.h
INCS			+= include/ft_cylinder.h
INCS			+= include/ft_scene.h
INCS			+= include/ft_camera.h
INCS			+= include/ft_lights.h
INCS			+= include/ft_ray.h
INCS			+= include/ft_vector.h
INCS			+= include/ft_utils.h

# Source files (Can be changed)

SRCS_MANDA		:= core/main.c
SRCS_MANDA		+= core/main_utils.c
SRCS_MANDA		+= deque/ft_deque_0.c
SRCS_MANDA		+= deque/ft_deque_1.c
SRCS_MANDA		+= deque/ft_deque_2.c
SRCS_MANDA		+= deque/ft_deque_3.c
SRCS_MANDA		+= minirt/ft_minirt_create_window.c
SRCS_MANDA		+= minirt/ft_minirt_message_loop.c
SRCS_MANDA		+= minirt/ft_minirt_destroy.c
SRCS_MANDA		+= minirt/ft_minirt_hook.c
SRCS_MANDA		+= minirt/ft_minirt_hook2.c
SRCS_MANDA		+= minirt/ft_minirt_hook3.c
SRCS_MANDA		+= minirt/ft_minirt_hook_utils.c
SRCS_MANDA		+= graphic/ft_graphic.c
SRCS_MANDA		+= graphic/ft_graphic_setup.c
SRCS_MANDA		+= graphic/ft_graphic_render.c
SRCS_MANDA		+= object/ft_objects.c
SRCS_MANDA		+= object/ft_objects_setup.c
SRCS_MANDA		+= object/ft_objects_hit.c
SRCS_MANDA		+= object/ft_sphere.c
SRCS_MANDA		+= object/ft_sphere_setup.c
SRCS_MANDA		+= object/ft_sphere_hit.c
SRCS_MANDA		+= object/ft_plane.c
SRCS_MANDA		+= object/ft_plane_setup.c
SRCS_MANDA		+= object/ft_plane_hit.c
SRCS_MANDA		+= object/ft_cylinder.c
SRCS_MANDA		+= object/ft_cylinder_setup.c
SRCS_MANDA		+= object/ft_cylinder_hit.c
SRCS_MANDA		+= object/ft_cylinder_hit_utils.c
SRCS_MANDA		+= scene/ft_scene.c
SRCS_MANDA		+= scene/ft_camera.c
SRCS_MANDA		+= scene/ft_camera_setup.c
SRCS_MANDA		+= scene/ft_camera_viewport.c
SRCS_MANDA		+= scene/ft_lights.c
SRCS_MANDA		+= scene/ft_lights_setup.c
SRCS_MANDA		+= scene/ft_lights_value.c
SRCS_MANDA		+= ray/ft_ray.c
SRCS_MANDA		+= ray/ft_ray_color.c
SRCS_MANDA		+= ray/ft_ray_phong_lighting.c
SRCS_MANDA		+= ray/ft_ray_phong_lighting_utils.c
SRCS_MANDA		+= vector/ft_vector_0.c
SRCS_MANDA		+= vector/ft_vector_1.c
SRCS_MANDA		+= vector/ft_vector_2.c
SRCS_MANDA		+= vector/ft_vector_3.c
SRCS_MANDA		+= utils/ft_utils.c

SRCS_BONUS		:= core/main.c
SRCS_BONUS		+= core/main_utils.c
SRCS_BONUS		+= deque/ft_deque_0.c
SRCS_BONUS		+= deque/ft_deque_1.c
SRCS_BONUS		+= deque/ft_deque_2.c
SRCS_BONUS		+= deque/ft_deque_3.c
SRCS_BONUS		+= minirt/ft_minirt_create_window.c
SRCS_BONUS		+= minirt/ft_minirt_message_loop.c
SRCS_BONUS		+= minirt/ft_minirt_destroy.c
SRCS_BONUS		+= minirt/ft_minirt_hook.c
SRCS_BONUS		+= minirt/ft_minirt_hook2.c
SRCS_BONUS		+= minirt/ft_minirt_hook3.c
SRCS_BONUS		+= minirt/ft_minirt_hook_utils.c
SRCS_BONUS		+= graphic/ft_graphic.c
SRCS_BONUS		+= graphic/ft_graphic_setup.c
SRCS_BONUS		+= graphic/ft_graphic_render.c
SRCS_BONUS		+= object/ft_objects.c
SRCS_BONUS		+= object/ft_objects_setup.c
SRCS_BONUS		+= object/ft_objects_hit.c
SRCS_BONUS		+= object/ft_sphere.c
SRCS_BONUS		+= object/ft_sphere_setup.c
SRCS_BONUS		+= object/ft_sphere_hit.c
SRCS_BONUS		+= object/ft_plane.c
SRCS_BONUS		+= object/ft_plane_setup.c
SRCS_BONUS		+= object/ft_plane_hit.c
SRCS_BONUS		+= object/ft_cylinder.c
SRCS_BONUS		+= object/ft_cylinder_setup.c
SRCS_BONUS		+= object/ft_cylinder_hit.c
SRCS_BONUS		+= object/ft_cylinder_hit_utils.c
SRCS_BONUS		+= scene/ft_scene_bonus.c
SRCS_BONUS		+= scene/ft_camera.c
SRCS_BONUS		+= scene/ft_camera_setup.c
SRCS_BONUS		+= scene/ft_camera_viewport.c
SRCS_BONUS		+= scene/ft_lights.c
SRCS_BONUS		+= scene/ft_lights_setup_bonus.c
SRCS_BONUS		+= scene/ft_lights_value.c
SRCS_BONUS		+= ray/ft_ray.c
SRCS_BONUS		+= ray/ft_ray_color.c
SRCS_BONUS		+= ray/ft_ray_phong_lighting.c
SRCS_BONUS		+= ray/ft_ray_phong_lighting_utils.c
SRCS_BONUS		+= vector/ft_vector_0.c
SRCS_BONUS		+= vector/ft_vector_1.c
SRCS_BONUS		+= vector/ft_vector_2.c
SRCS_BONUS		+= vector/ft_vector_3.c
SRCS_BONUS		+= utils/ft_utils.c

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

CC				= cc
OBJS_MANDA		= $(SRCS_MANDA:.c=.o)
OBJS_BONUS		= $(SRCS_BONUS:.c=.o)

# Linked libraries at compile time (Can be changed).

LIBS			:= -L$(LFT_DIR) -lft
LIBS			+= -L$(LMLX_DIR) -lmlx
LIBS			+= -lm

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

bonus:
	@make BONUS_FLAG=1

$(NAME): $(LFT) $(LMLX) $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@install_name_tool -change $(MLX) $(LMLX) $(NAME)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Libraries installion using their own Makefile (Can be changed).

$(LFT):
	@make -sC $(LFT_DIR) -j

$(LMLX):
	@make -sC $(LMLX_DIR)

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

fclean:
	@make clean
	@make -sC $(LFT_DIR) fclean
	@make -sC $(LMLX_DIR) clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)

# Re-build libs (Can't be changed).

re-libs: $(OBJS_DIR) $(C_SUBDIRS) $(C_OBJS)
	@make -sC $(LFT_DIR) re
	@echo "$(YELLOW)      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@install_name_tool -change $(MLX) $(LMLX) $(NAME)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Re-compile everything (Can't be changed).

re:
	@make fclean
	@make all

# Avoid unexpected behaviour when regular files
# get the same name as the following variables (Can be changed).

.PHONY: all clean fclean re bonus
