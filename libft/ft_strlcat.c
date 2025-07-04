/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:54:22 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/13 15:54:29 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	if (size != 0)
	{
		while (j + i < (size - 1) && src[j] != '\0')
		{
			dest[i + j] = src[j];
			j++;
		}
	}
	if (i < size)
		dest[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}
/*
int	main(void)
{
	char dest1[] = "H";
	char src1[] = "ola";

	printf("%d\n", ft_strlcat(dest1, src1, 4));
	printf("%s\n", dest1);

	char dest2[] = "H";
 	char src2[] = "";

        printf("%d\n", ft_strlcat(dest2, src2, 20));
        printf("%s\n", dest2);

	char dest3[] = "";
        char src3[] = "ola";

        printf("%d\n", ft_strlcat(dest3, src3, 4));
        printf("%s\n", dest3);
}*/
