/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:07:12 by ancarret          #+#    #+#             */
/*   Updated: 2025/07/09 13:31:38 by ancarret         ###   ########.fr       */
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

int ft_exit(char **args)
{
    
}