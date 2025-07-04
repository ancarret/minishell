/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:21:42 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/23 09:26:15 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	ch;
	size_t			i;

	string = s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		string[i] = ch;
		i++;
	}
	return (s);
}
