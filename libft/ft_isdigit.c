/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:44:42 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/13 15:45:04 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>
int main(void){
    printf("%d\n", ft_isdigit('a'));
    printf("%d\n", ft_isdigit('9'));
    printf("%d\n", ft_isdigit('?'));
    printf("%d\n", ft_isdigit(2));
    printf("%d\n", ft_isdigit(0));
    printf("----------------\n");
    printf("%d\n", isdigit('a'));
    printf("%d\n", isdigit('9'));
    printf("%d\n", isdigit('?'));
    printf("%d\n", isdigit(2));
    printf("%d\n", isdigit(0));
}
*/