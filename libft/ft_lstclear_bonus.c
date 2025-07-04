/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:32:23 by ancarret          #+#    #+#             */
/*   Updated: 2025/01/26 14:32:24 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux_1;
	t_list	*aux_2;

	aux_1 = *lst;
	while (aux_1 != NULL)
	{
		aux_2 = aux_1->next;
		(*del)(aux_1->content);
		free(aux_1);
		aux_1 = aux_2;
	}
	*lst = NULL;
}
