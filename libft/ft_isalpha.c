/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:43:13 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/13 15:43:37 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}

/*#include <stdio.h>
int main(void){
    printf("%d\n", ft_isalpha('a'));
    printf("%d\n", ft_isalpha('9'));
    printf("%d\n", ft_isalpha('?'));
    printf("%d\n", ft_isalpha('E'));
}*/
