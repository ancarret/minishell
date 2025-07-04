/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:55:16 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/23 15:05:29 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*first;
	unsigned char	*sec;
	size_t			i;

	first = (unsigned char *)s1;
	sec = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (first[i] != sec[i])
			return (first[i] - sec[i]);
		i++;
	}
	return (0);
}
