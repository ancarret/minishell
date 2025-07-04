/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:40:55 by ancarret          #+#    #+#             */
/*   Updated: 2025/02/09 09:45:22 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reverse(char *result)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = ft_strlen(result) - 1;
	while (i < j)
	{
		aux = result[i];
		result[i] = result[j];
		result[j] = aux;
		i++;
		j--;
	}
}

int	correct_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base [j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(unsigned long nb, char *base)
{
	int		size;
	int		index;
	char	result[1000];

	index = 0;
	size = ft_strlen(base);
	if (!correct_base(base))
		return (0);
	if (nb == 0)
	{
		write(1, &base[0], 1);
		return (1);
	}
	while (nb > 0)
	{
		result[index++] = base[nb % size];
		nb /= size;
	}
	result[index] = '\0';
	reverse(result);
	write(1, result, ft_strlen(result));
	return (ft_strlen(result));
}
