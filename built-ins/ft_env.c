/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:16:15 by ancarret          #+#    #+#             */
/*   Updated: 2025/07/09 13:16:18 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_env(char **envp)
{
    int i;
    char *c;
    
    i = 0;
    while (envp[i])
    {
        c = ft_strchr(envp[i], '=');
        if (c)
            printf("%s\n", envp[i]);
        i++;
    }
    return (0);
}