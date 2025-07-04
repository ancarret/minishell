/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:22:41 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/24 12:58:56 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		index;
	int		number;
	char	sign;

	index = 0;
	number = 0;
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n'
		|| str[index] == '\r' || str[index] == '\v' || str[index] == '\f')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		sign = str[index];
		index++;
	}
	while (str[index] != '\0' && is_numeric(str[index]))
	{
		number *= 10;
		number = number + ((int)str[index] - 48);
		index++;
	}
	if (sign == '-')
		number = -number;
	return (number);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	char *test1 = argv[1];

	printf("%d\n", ft_atoi(test1));
	printf("%d\n", atoi(test1));
}*/