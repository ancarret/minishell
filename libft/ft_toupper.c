/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:55:47 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/23 10:55:53 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
    printf("%d\n", ft_toupper('a'));
    printf("%d\n", ft_toupper('A'));
    printf("%d\n", ft_toupper('5'));
    printf("%d\n", toupper('a'));
    printf("%d\n", toupper('A'));
    printf("%d\n", toupper('5'));
}*/
