/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:07:12 by ancarret          #+#    #+#             */
/*   Updated: 2025/07/09 15:28:07 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Casos a tener en cuenta del exit:
Entrada	        Salida	                            Código salida	    Termina Shell
exit	        exit	                            Último $?	        Sí
exit 42	        exit	                            42	                Sí
exit foo	    exit + error numérico	            2	                Sí
exit 1 2	    exit + error demasiados args	    1	                No
exit foo bar	exit + error numérico	            2	                Sí
exit >max_int	exit + error numérico	            2	                Sí
*/

static int count_args (char **args)
{
    int i;

    i = 0;
    while (args[i])
        i++;
    return (i);
}

int ft_exit(t_data *data, char **args)
{
    int num_args;
    int exit_code;

    num_args = count_args(args);
    if (num_args == 1)
        exit(data->last_exit_code);
    else if (num_args == 2)
    {
        exit_code = ft_atoi(args[1]);
        if (args[1])
    }
}