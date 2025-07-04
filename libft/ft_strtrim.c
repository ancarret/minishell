/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:33:46 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/26 14:33:47 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*result;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != '\0' && is_set(s1[i], (char *)set))
		i++;
	while (j > i && is_set(s1[j - 1], (char *)set))
		j--;
	len = j - i;
	result = ft_substr((char *)s1, (unsigned int)i, len);
	return (result);
}
