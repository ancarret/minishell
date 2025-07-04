/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:10:20 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/26 16:12:52 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	aux_str(char *str, char *to_find, int i, size_t len)
{
	size_t	j;

	j = 0;
	while (str[i + j] == to_find[j] && (i + j) < len)
	{
		j++;
		if (to_find[j] == '\0')
			return (1);
	}
	return (0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;
	char		*res;

	i = 0;
	res = NULL;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == to_find[0] && aux_str((char *)str, (char *) \
		to_find, i, len))
		{
			res = (char *)(str + i);
			break ;
		}
		i++;
	}
	return (res);
}
