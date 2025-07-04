/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:56:31 by ancarret          #+#    #+#             */
/*   Updated: 2025/06/05 15:00:01 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token *get_input_or_heredoc_token(char *input, int *i)
{
    char *value;
    t_token_type type;

    value = ft_strdup("<");
    type = TOKEN_REDIRECT_INPUT;
    (*i)++;
    if (input[*i] == '<')
    {
        free(value);
        value = ft_strdup("<<");
        type = TOKEN_HEREDOC;
        (*i)++;
    }
    return (create_token(value, type));
}

t_token *get_output_or_append_token(char *input, int *i)
{
    char *value;
    t_token_type type;

    value = ft_strdup(">");
    type = TOKEN_REDIRECT_OUTPUT;
    (*i)++;
    if (input[*i] == '>')
    {
        free(value);
        value = ft_strdup(">>");
        type = TOKEN_APPEND;
        (*i)++;
    }
    return (create_token(value, type));
}

t_token *get_quote_token(char *input, int *i, char quote)
{
    int start;
    char *value;
    t_token_type type;

    (*i)++;
    start = *i;
    while (input[*i] && input[*i] != quote)
        (*i)++;
    if (input[*i] != quote)
        return (NULL);
    value = ft_substr(input, start, *i - start);
    type = TOKEN_WORD;
    (*i)++;
    return (create_token(value, type));
}

t_token *get_special_token(char *input, int *i)
{
    char *value;
    t_token_type type;

    if (input[*i] == '|')
    {
        value = ft_strdup("|");
        type = TOKEN_PIPE;
        (*i)++;
        return (create_token(value, type));
    }
    else if (input[*i] == '<')
        return (get_input_or_heredoc_token(input, i));
    else if (input[*i] == '>')
        return get_output_or_append_token(input, i);
    return (NULL); 
}

t_token *get_word_token(char *input, int *i)
{
    int start;
    char *value;
    t_token_type type;

    start = *i;
    while (input[*i] && !is_token_breaker(input[*i]))
        (*i)++;
    value = ft_substr(input, start, *i - start);
    type = TOKEN_WORD;
    return (create_token(value, type));
}