/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:46:03 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/23 14:52:19 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_strlen("Hola"));
    printf("%d\n", ft_strlen("Hola que tal estas"));
    printf("%d\n", ft_strlen("Hola estoy probando la funcion"));
    printf("%d\n", ft_strlen(""));
}*/
