NAME := miniRT

ifeq ($(shell uname), Linux)
	MLXFLAGS += -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MLX_LIB := libmlx_Linux.a
else
	MLXFLAGS += -L/usr/X11R6/lib -Imlx -lX11 -lXext -framework OpenGL -framework AppKit
	MLX_LIB := libmlx_Darwin.a
endif

INC := -I ./libft -I ./mlx_linux -I ./srcs -I ./srcs/math_utils -I ./srcs/color_utils -I ./srcs/mlx_utils -I ./srcs/parse -I ./srcs/object_utils -I ./srcs/get_next_line -I ./srcs/utils -I ./srcs/raytrace
SRCS_DIR := ./srcs
OBJS_DIR := ./objs
DEPS_DIR := ./deps
MLX_DIR := ./mlx_linux
LIBFT_DIR := ./libft

CFLAGS := -fsanitize=address -g $(INC) #-Wall -Wextra -Werror

SRCS := $(shell find $(SRCS_DIR)/* -name "*.c" -type f)
OBJS := $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
DEPS := $(SRCS:$(SRCS_DIR)/%.c=$(DEPS_DIR)/%.d)

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
