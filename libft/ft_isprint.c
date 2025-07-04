/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:45:22 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/13 15:45:47 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*#include <stdio.h>
int main(void){
    printf("%d\n", ft_isprint('a'));
    printf("%d\n", ft_isprint('9'));
    printf("%d\n", ft_isprint('\n'));
    printf("%d\n", ft_isprint('2'));
}*/
