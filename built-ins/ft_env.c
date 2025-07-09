/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almudenalopezrodriguez <almudenalopezro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:07:32 by ancarret          #+#    #+#             */
/*   Updated: 2025/07/08 12:12:38 by almudenalop      ###   ########.fr       */
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