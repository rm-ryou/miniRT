NAME := miniRT

ifeq ($(shell uname), Linux)
	MLXFLAGS += -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MLX_LIB := libmlx_Linux.a
else
	MLXFLAGS += -L/usr/X11R6/lib -Imlx -lX11 -lXext -framework OpenGL -framework AppKit
	MLX_LIB := libmlx_Darwin.a
endif

INC += -I ./libft -I ./mlx_linux
SRCS_DIR := ./srcs
OBJS_DIR := ./objs
DEPS_DIR := ./deps
MLX_DIR := ./mlx_linux
LIBFT_DIR := ./libft


INC += -I ./srcs
SRCS += $(addprefix ./srcs/, main.c)
INC += -I ./srcs/math_utils
SRCS += $(addprefix ./srcs/math_utils/, \
						math_basic_ope.c \
						math_utils.c)
INC += -I ./srcs/color_utils
SRCS += $(addprefix ./srcs/color_utils/, \
						color_basic_ope.c \
						color_utils.c)
INC += -I ./srcs/get_next_line
SRCS += $(addprefix ./srcs/get_next_line/, get_next_line.c)
INC += -I ./srcs/mlx_utils
SRCS += $(addprefix ./srcs/mlx_utils/, \
						mlx_hooks.c \
						mlx_utils.c)
INC += -I ./srcs/object_utils
SRCS += $(addprefix ./srcs/object_utils/, object_utils.c)
INC += -I ./srcs/parse
SRCS += $(addprefix ./srcs/parse/, \
						list_utils.c \
						parser_object.c \
						parser_utils.c \
						read_line.c \
						set_line.c)
INC += -I ./srcs/raytrace
SRCS += $(addprefix ./srcs/raytrace/, \
						raytrace_utils.c \
						raytrace.c \
						solve_cylinder.c \
						solve_plane.c \
						solve_sphere.c)
INC += -I ./srcs/utils
SRCS += $(addprefix ./srcs/utils/, \
						free_all.c \
						free_darray.c \
						free_path.c \
						get_double.c \
						put_message_exit.c \
						x_malloc.c \
						x_open.c)
OBJS := $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
DEPS := $(SRCS:$(SRCS_DIR)/%.c=$(DEPS_DIR)/%.d)

CFLAGS := -fsanitize=address -g $(INC) -Wall -Wextra -Werror

RM := rm -rf

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_DIR)/$(MLX_LIB) $(LIBFT_DIR)/libft.a -o $@ $(MLXFLAGS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)/$(*D)
	@mkdir -p $(DEPS_DIR)/$(*D)
	$(CC) $(CFLAGS) -MP -MMD -MF $(DEPS_DIR)/$(*).d -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

-include $(DEPS)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)
	$(RM) $(DEPS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

test: all
	@echo "\033[31m************************\033[m"
	@./$(NAME) ./scene/basic_sphere.rt

.PHONY: all clean fclean re
