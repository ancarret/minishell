/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:01:45 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/13 16:04:35 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n)
	{
		if (s1[index] == '\0' && s2[index] == '\0')
			return (0);
		else if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}
/*
int	main(void)
{
	char	test1[] = "Holaa";
	char	test2[] = "Hola";
	char	test3[] = "Adios";
	char	test4[] = "Holb";
	char    test5[] = "H";
	char    test6[] = "";


	printf("'%s' y '%s',  %d\n", test1, test2, ft_strncmp(test1, test2, 7));
	printf("'%s' y '%s',  %d\n", test1, test3, ft_strncmp(test1, test3, 3));
	printf("'%s' y '%s',  %d\n", test2, test4, ft_strncmp(test2, test4, 3));
	printf("'%s' y '%s',  %d\n", test2, test4, ft_strncmp(test2, test4, 4));
	printf("'%s' y '%s',  %d\n", test4, test2, ft_strncmp(test4, test2, 4));
	printf("'%s' y '%s',  %d\n", test1, test5, ft_strncmp(test1, test5, 2));
	printf("'%s' y '%s',  %d\n", test1, test6, ft_strncmp(test1, test6, 2));
	printf("%d\n", ft_strncmp("test\1","test\200", 6));

	printf("'%s' y '%s',  %d\n", test1, test2, strncmp(test1, test2, 7));
    printf("'%s' y '%s',  %d\n", test1, test3, strncmp(test1, test3, 3));
    printf("'%s' y '%s',  %d\n", test2, test4, strncmp(test2, test4, 3));
	printf("'%s' y '%s',  %d\n", test2, test4, strncmp(test2, test4, 4));
	printf("'%s' y '%s',  %d\n", test4, test2, strncmp(test4, test2, 4));
	printf("'%s' y '%s',  %d\n", test1, test5, strncmp(test1, test5, 2));
	printf("'%s' y '%s',  %d\n", test1, test6, strncmp(test1, test6, 2));
	printf("%d\n", strncmp("test\1","test\200", 6));
}
*/
