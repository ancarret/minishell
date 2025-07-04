/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 08:00:43 by ancarret          #+#    #+#             */
/*   Updated: 2025/06/04 09:01:00 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	aux;
	int	index;

	index = 0;
	while (s1[index] != '\0' && s1[index] == s2[index])
		index++;
	aux = s1[index] - s2[index];
	return (aux);
}
