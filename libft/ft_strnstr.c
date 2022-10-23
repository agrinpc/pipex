/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:34:30 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/30 14:41:44 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	int		j;
	size_t	size;
	char	*new_big;

	size = 0;
	j = -1;
	new_big = (char *)big;
	size = ft_strlen(little);
	if (!little || size == 0)
		return (new_big);
	while (new_big[++j] && n > 0)
	{
		if (new_big[j] == little[0] && n >= size)
		{
			if (ft_strncmp(new_big + j, little, size) == 0)
				return (new_big + j);
		}
		n--;
	}
	return (NULL);
}
