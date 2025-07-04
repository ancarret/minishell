/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:40:48 by ancarret          #+#    #+#             */
/*   Updated: 2025/02/09 09:45:47 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	char	number;
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len += 1;
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
	}
	number = (n % 10) + 48;
	write(1, &number, 1);
	len += 1;
	return (len);
}

int	ft_putunsigned(unsigned int n)
{
	char	number;
	int		len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putunsigned(n / 10);
	}
	number = (n % 10) + 48;
	write(1, &number, 1);
	len += 1;
	return (len);
}

int	ft_pointer(void *ptr)
{
	unsigned long	address;
	int				len;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)ptr;
	write(1, "0x", 2);
	len = 2;
	len += ft_putnbr_base(address, "0123456789abcdef");
	return (len);
}

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	len = ft_strlen(s);
	return (len);
}
