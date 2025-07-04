/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:47:06 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/13 15:47:31 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
    printf("%d\n", ft_tolower('a'));
    printf("%d\n", ft_tolower('A'));
    printf("%d\n", ft_tolower('5'));
    printf("%d\n", tolower('a'));
    printf("%d\n", tolower('A'));
    printf("%d\n", tolower('5'));
}*/
