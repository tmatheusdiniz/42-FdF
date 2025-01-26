# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 19:29:26 by mreinald          #+#    #+#              #
#    Updated: 2025/01/12 19:34:06 by mreinald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
RED	= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
MAGENTA	= \033[0;35m
CYAN	= \033[3;36m
RESET	= \033[0m

#Program's name
NAME	= bin/fdf

# Commands/flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
MLX		= ./libs/minilibx-linux/libmlx.a
UNAME_S := $(shell uname -s)
INCLUDES	= -I ./include -I ./libs/Libft/include

# Directories
SRC_DIR	= srcs
OBJ_DIR	= objs
BIN_DIR	= bin
LIBFT_DIR	= ./libs/Libft/
MINILIBX_DIR = ./libs/minilibx-linux/

SRCS	= $(wildcard $(SRC_DIR)/*/*.c)

OBJS	= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRCS:.c=.o))

# Libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L./$(LIBFT_DIR) -lft

# ASCII Art
define ART
$(MAGENTA)
  ███████╗██████╗ ███████╗    ██╗    ██╗██╗██████╗ ███████╗
  ██╔════╝██╔══██╗██╔════╝    ██║    ██║██║██╔══██╗██╔════╝
  █████╗  ██║  ██║█████╗      ██║ █╗ ██║██║██████╔╝█████╗
  ██╔══╝  ██║  ██║██╔══╝      ██║███╗██║██║██╔══██╗██╔══╝
  ██║     ██████╔╝██║         ╚███╔███╔╝██║██║  ██║███████╗
  ╚═╝     ╚═════╝ ╚═╝          ╚══╝╚══╝ ╚═╝╚═╝  ╚═╝╚══════╝
  $(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━[$(RESET)Made with $(RESET) by $(BLUE)@tmatheusdiniz$(CYAN)]━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)
endef
export ART

#condicional
ifeq ($(UNAME_S),Linux)
	INCLUDES += -I/usr/include/X11
	MLX_FLAGS += -L. -lXext -L. -lX11 -lm
endif

ifeq ($(UNAME_S),Darwin)
	INCLUDES += -I/opt/X11/include
	MLX_FLAGS += -L/opt/X11/lib -lX11 -lX11 -lXext -lXrandr -lXcursor -lXinerama -lXxf86vm -lXrender -lX11-xcb -lXfixes -lm
endif

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MLX)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(INCLUDES) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@clear
	@echo "$$ART"
	@echo "$(CYAN)fdf compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@sleep 0.02
	@clear
	@echo "$(RED)Compiling fdf sources $<$(RESET)"

$(MLX): $(MINILIBX_DIR)
	@make -C $^ > /dev/null 2>&1

$(LIBFT):
	@make --silent -C $(LIBFT_DIR)

clean:
	@make --silent -C ./libs/minilibx-linux clean
	@clear
	@make --silent -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make --silent -C ./libs/minilibx-linux clean
	@clear
	@make --silent -C $(LIBFT_DIR) fclean
	@rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
