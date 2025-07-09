# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almudenalopezrodriguez <almudenalopezro    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 10:51:46 by ancarret          #+#    #+#              #
#    Updated: 2025/07/08 12:07:38 by almudenalop      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra 
NAME = minishell
SRCS = main.c \
		lexer/lexer.c lexer/lexer_utils.c lexer/tokenizer.c lexer/tokenizer_utils.c \
		lexer/get_tokens.c parser/parser.c parser/parser_utils.c parser/get_commands.c \
		built-ins/ft_pwd.c built-ins/ft_echo.c built-ins/ft_env.c
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -lreadline

OBJS = $(SRCS:%.c=%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)

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