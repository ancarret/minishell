/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:59:04 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/13 15:59:06 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	count;

	index = 0;
	count = 0;
	while (src[count] != '\0')
	{
		count++;
	}
	if (size == 0)
	{
		return (count);
	}
	while (index < size - 1 && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	if (index < size)
	{
		dest[index] = '\0';
	}
	return (count);
}
/*
int main()
{
    // Caso 1: Copiar con espacio suficiente
    char src1[] = "Hola Mundo";
    char dest1[20];  // Tamaño grande

    unsigned int result1 = ft_strlcpy(dest1, src1, 20);

    printf("Caso 1: %u, dest1 = '%s'\n", result1, dest1);

    // Caso 2: Copiar con espacio justo
    char src2[] = "Hola";
    char dest2[5];  // Tamaño justo para copiar solo "Hola"

    unsigned int result2 = ft_strlcpy(dest2, src2, 5);

    printf("Caso 2: %u, dest2 = '%s'\n", result2, dest2);

    // Caso 3: Copiar con espacio limitado
    char src3[] = "Supercalifragilisticexpialidocious";
    char dest3[10];  // Buffer pequeño

    unsigned int result3 = ft_strlcpy(dest3, src3, 10);

    printf("Caso 3: %u, dest3 = '%s'\n", result3, dest3);

    return 0;
}
*/
