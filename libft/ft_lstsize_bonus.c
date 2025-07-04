/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:32:54 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/26 14:32:55 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*aux;

	if (!lst)
		return (0);
	aux = lst;
	count = 1;
	while (aux->next != NULL)
	{
		count++;
		aux = aux->next;
	}
	return (count);
}
