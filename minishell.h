/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:07:21 by ancarret          #+#    #+#             */
/*   Updated: 2025/07/09 12:38:18 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BLUE     "\033[34m"
# define GREEN    "\033[32m"
# define WHITE    "\033[0m"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

/*
Enumerados para clasificar el tipo de token
*/

typedef enum e_token_type
{
    TOKEN_WORD,                 // PALABRA
    TOKEN_PIPE,                 // |
    TOKEN_REDIRECT_INPUT,       // <
    TOKEN_REDIRECT_OUTPUT,      // >
    TOKEN_APPEND,               // >>
    TOKEN_HEREDOC,              // <<
    TOKEN_VAR,                  // $VAR
} t_token_type;

/*
Lista enlazada simple para guardar los tokens
*/

typedef struct s_token
{
    t_token_type type;
    char *value;
    struct s_token *next;
} t_token;

/*
Lista para guardar los comandos
*/

typedef struct s_command
{
    char **args;
    char *infile;
    char *outfile;
    int append;
    char *heredoc_limiter;
    struct s_command *next;
} t_command;

typedef struct s_data
{
    char *input_line;
    t_command *commands;
    t_token *tokens;
    char **envp;
} t_data;

/***********************************************
                    LEXER
************************************************/

/*lexer*/
void lexer(t_data *data);

/*lexer_utils*/
int	ft_strcmp(char *s1, char *s2);

/*tokenizer*/
t_token *get_next_token(char *input, int reset);
int is_special_character(char c);

/*get_tokens*/
t_token *get_input_or_heredoc_token(char *input, int *i);
t_token *get_output_or_append_token(char *input, int *i);
t_token *get_quote_token(char *input, int *i, char quote);
t_token *get_special_token(char *input, int *i);
t_token *get_word_token(char *input, int *i);

/*tokenizer_utils*/
t_token *create_token(char *value, t_token_type type);
void add_token(t_token **tokens, t_token *new_node);
void free_tokens(t_token *tokens);
int	is_space(char c);
int is_token_breaker(char c);

/***********************************************
                    PARSER
************************************************/

/*parser*/
void parser(t_data *data);

/*parser_utils*/
t_command *create_command(void);
void add_command(t_command **commands, t_command *new_node);
void free_commands(t_command *cmd);

/*get_commands*/
t_command *get_next_command(t_data *data, int reset);

/***********************************************
                    BUILT-INS
************************************************/

int ft_pwd(void);
int ft_echo(char **args);
int ft_env(char **envp);


/***********************************************
                    EXECUTOR
************************************************/

int     execute_commands(t_command *commands, char **envp);
void    execute_child(t_command cmd, char **envp);



/***********************************************
                    PIPES
************************************************/

void initialize_pipe(int pipefd[2], int i, int n);
void redirect_pipe(int pipefd[2], int i, int n, int last_pipe);

#endif