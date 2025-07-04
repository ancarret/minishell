/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 08:43:25 by ancarret          #+#    #+#             */
/*   Updated: 2025/06/05 15:15:20 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_special_character(char c)
{
    return (c == '|' || c == '<' || c == '>' || c == '$');
}

t_token *get_next_token(char *input, int reset)
{
    static int i;

    if (reset)
        i = 0;
    while(input[i])
    {
        while (input[i] && is_space(input[i]))
            i++;
        if (!input)
            return (NULL);
        if (input[i] == '\'')
            return get_quote_token(input, &i, '\'');
        else if (input[i] == '"')
            return get_quote_token(input, &i, '"');
        else if (is_special_character(input[i]))
            return get_special_token(input, &i);
        else
            return get_word_token(input, &i);
    }
    return (NULL);
}
