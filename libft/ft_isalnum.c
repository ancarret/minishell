/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:26:22 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/13 15:27:00 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c >= 48 && c <= 57))
		return (1);
	return (0);
}

/*#include <stdio.h>
int main(void){
    printf("%d\n", ft_isalnum('a'));
    printf("%d\n", ft_isalnum('9'));
    printf("%d\n", ft_isalnum('?'));
    printf("%d\n", ft_isalnum('E'));
}*/
