# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 10:51:46 by ancarret          #+#    #+#              #
#    Updated: 2025/07/09 13:03:58 by ancarret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra 
NAME = minishell
SRCS = 			main.c \
				lexer/lexer.c \
				lexer/lexer_utils.c \
				lexer/tokenizer.c \
				lexer/tokenizer_utils.c \
				lexer/get_tokens.c \
				parser/parser.c \
				parser/parser_utils.c \
				parser/get_commands.c \
				built-ins/ft_pwd.c \
				built-ins/ft_echo.c \
				built-ins/ft_env.c \
				executor/execute.c \
				executor/child.c \
				executor/pipe.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -lreadline

OBJS = $(SRCS:%.c=%.o)

all: $(LIBFT) $(NAME)
	
$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)
	@echo ""
	@echo "\033[38;5;120m                   o8o               o8o           oooo                  oooo  oooo  \033[0m"
	@echo "\033[38;5;119m                   \`\"\'               \`\"\'           \`888                  \`888  \`888  \033[0m"
	@echo "\033[38;5;118mooo. .oo.  .oo.   oooo  ooo. .oo.   oooo   .oooo.o  888 .oo.    .ooooo.   888   888  \033[0m"
	@echo "\033[38;5;83m\`888P\"Y88bP\"Y88b  \`888  \`888P\"Y88b  \`888  d88(  \"8  888P\"Y88b  d88\' \`88b  888   888  \033[0m"
	@echo "\033[38;5;77m 888   888   888   888   888   888   888  \`\"Y88b.   888   888  888ooo888  888   888  \033[0m"
	@echo "\033[38;5;41m 888   888   888   888   888   888   888  o.  )88b  888   888  888    .o  888   888  \033[0m"
	@echo "\033[38;5;35mo888o o888o o888o o888o o888o o888o o888o 8\"\"888P\' o888o o888o \`Y8bod8P\' o888o o888o \033[0m"
	@echo "\033[34m                              by fealonso & ancarret\033[0m"
	@echo ""

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME) $(OBJS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re