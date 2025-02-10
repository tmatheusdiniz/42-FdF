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
