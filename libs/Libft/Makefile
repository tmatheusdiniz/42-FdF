# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 22:38:40 by mreinald          #+#    #+#              #
#    Updated: 2024/11/10 00:41:56 by mreinald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color
RESET = \033[0m
GREEN = \033[32m
BLUE = \033[34m
YELLOW = \033[33m
RED = \033[31m
CYAN = \033[36m
WHITE = \033[3;37m

#library name
NAME = libft.a

#my old config
ifeq "1" "2"
stdio_h = ft_putchar.c

stdlib_h = ft_atoi.c ft_strdup.c ft_calloc.c

string_h = ft_strlen.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c

strings_h = ft_bzero.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c

ctype_h = ft_isalnum.c ft_isascii.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_toupper.c ft_tolower.c ft_isupper.c ft_islower.c

non_stardad = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_substr.c ft_strtrim.c ft_strjoin.c ft_split.c ft_strmapi.c ft_striteri.c ft_putstr.c

linked_list = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

ft_printf_h = ./ft_printf/ft_printf.c \
		./ft_printf/char_handler.c \
		./ft_printf/ft_printf_flags.c \
		./ft_printf/ft_printf_utils.c \
		./ft_printf/ft_printf_utils_int.c \
		./ft_printf/ft_printf_utils_unsig.c \
		./ft_printf/hexdecimal_handler.c \
		./ft_printf/integer_handler.c \
		./ft_printf/percentage_handler.c \
		./ft_printf/pointer_handler.c \
		./ft_printf/string_handler.c \
		./ft_printf/unsignedint_handler.c

get_next_line_h =  ./get_next_line/srcs/get_next_line.c \
			./get_next_line/srcs/get_next_line_utils.c \
			./get_next_line/srcs/get_next_line_bonus.c \
			./get_next_line/srcs/get_next_line_utils_bonus.c

SRC = ${stdio_h} ${stdlib_h} ${string_h} ${strings_h} ${ctype_h} ${non_stardad} ${ft_printf_h} ${get_next_line_h}
endif

#Directories
SRC = $(wildcard srcs/*.c) $(wildcard ft_printf/*/*.c) $(wildcard get_next_line/*/*.c)
OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${linked_list:.c=.o}

#commands and flags
COMPILER = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@clear
	@echo
	@echo
	@echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
	@echo "\033[33m    ██╗     ██╗██████╗ ███████╗████████╗      ██╗     ██╗██████╗ ██████╗  █████╗ ██████╗ ██╗   ██╗"
	@echo "    ██║     ██║██╔══██╗██╔════╝╚══██╔══╝      ██║     ██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝"
	@echo "    ██║     ██║██████╔╝█████╗     ██║   █████╗██║     ██║██████╔╝██████╔╝███████║██████╔╝ ╚████╔╝ "
	@echo "    ██║     ██║██╔══██╗██╔══╝     ██║   ╚════╝██║     ██║██╔══██╗██╔══██╗██╔══██║██╔══██╗  ╚██╔╝  "
	@echo "    ███████╗██║██████╔╝██║        ██║         ███████╗██║██████╔╝██║  ██║██║  ██║██║  ██║   ██║   "
	@echo "    ╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝         ╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   \033[0m"
	@echo "\033[30m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
	@echo
	@echo "$(WHITE) Successfully compiled Libft.$(RESET)"
	@echo

.c.o:
	@${COMPILER} ${CFLAGS} -c $< -o $@
	@sleep 0.02
	@clear
	@echo "$(MAGENTA)    ▒█▀▀█ ▒█░▒█ ▀█▀ ▒█░░░ ▒█▀▀▄ ▀█▀ ▒█▄░▒█ ▒█▀▀█  "
	@echo "    ▒█▀▀▄ ▒█░▒█ ▒█░ ▒█░░░ ▒█░▒█ ▒█░ ▒█▒█▒█ ▒█░▄▄  "
	@echo "    ▒█▄▄█ ░▀▄▄▀ ▄█▄ ▒█▄▄█ ▒█▄▄▀ ▄█▄ ▒█░░▀█ ▒█▄▄█  "
	@echo "                    $(RED)Libft building$(RESET)$(MAGENTA)"
	@echo

all: ${NAME}

bonus: ${OBJS} ${OBJS_BONUS}
	@ar rcs ${NAME} $^
	@echo "$(GREEN)Bonus functions successfully compiled!$(RESET)"

clean:
	@${RM} ${OBJS} ${OBJS_BONUS}
	@rm -rf ./ft_printf/srcs/*.o
	@rm -rf ./get_next_line/srcs/*.o
	@clear
	@echo "$(RED)╔═══════════════════╗"
	@echo "║  FULL CLEAN DONE  ║"
	@echo "╚═══════════════════╝$(RESET)"
	@echo "$(GREEN)▰▰▰▰▰▰▰▰▰▰ 100%$(RESET)"
	@echo "$(RED)All objects cleaned!$(RESET)"	

fclean: clean
	@${RM} ${NAME}
	@clear
	@echo
	@echo "$(RED)╔═══════════════════╗"
	@echo "║  FULL CLEAN DONE  ║"
	@echo "╚═══════════════════╝$(RESET)"
	@echo "$(GREEN)▰▰▰▰▰▰▰▰▰▰ 100%$(RESET)"
	@echo "$(RED)Everything cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
