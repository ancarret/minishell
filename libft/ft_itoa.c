/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:28:31 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/26 14:28:32 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_negative(int n)
{
	return (n < 0);
}

int	get_size(int num)
{
	int	size;

	size = 1;
	if (num < 0)
	{
		size++;
		num = -num;
	}
	while (num > 9)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;
	int		num;

	num = n;
	size = get_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		n = -n;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size] = '\0';
	while (size > 0)
	{
		result[size - 1] = (n % 10) + 48;
		n /= 10;
		size--;
	}
	if (is_negative(num))
		result[0] = '-';
	return (result);
}
