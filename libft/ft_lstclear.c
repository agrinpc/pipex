/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:26:47 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/31 11:49:40 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!lst)
		return ;
	if (!*lst || !del)
		return ;
	tmp1 = *lst;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		del(tmp1->content);
		free(tmp1);
		tmp1 = tmp2;
	}
	*lst = NULL;
}
