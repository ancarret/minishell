/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:38:41 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/23 14:00:39 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	int				aux;
	int				i;

	i = 0;
	aux = -1;
	ch = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (ch == s[i])
			aux = i;
		i++;
	}
	if (aux != -1)
		return ((char *)(s + aux));
	if (ch == '\0')
		return ((char *)(s + i));
	return (NULL);
}
