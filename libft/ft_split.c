/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:33:20 by ancarret          #+#    #+#             */
/*   Updated: 2025/06/02 09:31:57 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

int	size_str(char *str, int i, char c)
{
	int	j;
	int	count;

	j = i;
	count = 0;
	while (str[j] != '\0')
	{
		if (str[j] == c)
			return (count);
		count++;
		j++;
	}
	return (count);
}

void	free_result(char **result, int position)
{
	while (position > 0)
	{
		free(result[position - 1]);
		position--;
	}
	free(result);
}

int	if_null_free_result(char **result, int position)
{
	if (result[position] == NULL)
	{
		free_result(result, position);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		size;
	int		position;

	result = (char **)malloc((num_words((char *)s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	position = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			size = size_str((char *)s, i, c);
			result[position++] = ft_substr((char *)s, i, size);
			if (!if_null_free_result(result, position - 1))
				return (NULL);
			i += size;
		}
	}
	result[position] = NULL;
	return (result);
}
/*
int main(void)
{
	char str[] = "xxxxxxxxhello!";
	char charset = 'x';
	char **result;
	int i;

	result = ft_split(str, charset);
	if (result)
	{
		for (i = 0; result[i] != NULL; i++)
		{
			printf("Token %d: %s\n", i + 1, result[i]);
			free(result[i]);
		}
		free(result);
	}
	return 0;
}*/