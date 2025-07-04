/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:03:25 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/24 10:39:08 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (dest);
	if (dest < src)
	{
		return (ft_memcpy(dest, src, n));
	}
	else
	{
		d = (unsigned char *)dest;
		s = (unsigned char *)src;
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}
