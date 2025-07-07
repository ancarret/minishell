/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:07:45 by ancarret          #+#    #+#             */
/*   Updated: 2025/07/07 11:00:50 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(void)
{
	char	buffer[1024];
	char	*res;

	res = getcwd(buffer, sizeof(buffer));
	if (res == NULL)
	{
		perror("minishell: pwd");
		return (1);
	}
	printf("%s\n", buffer);
	return (0);
}