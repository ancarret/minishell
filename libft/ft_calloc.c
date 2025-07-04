/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:28:25 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/26 14:28:26 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;
	char	*aux_ptr;

	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	aux_ptr = (char *)ptr;
	while (i < nmemb * size)
	{
		aux_ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
