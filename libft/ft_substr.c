/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:05:11 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/31 18:11:24 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	size;

	if (!s && !start)
		return (NULL);
	i = -1;
	size = ft_strlen(s);
	if (size < len)
		len = size;
	sub = malloc(len + 1);
	if (!sub)
	{
		free(sub);
		return (NULL);
	}
	if ((size_t)start >= size)
	{
		sub[0] = 0;
		return (sub);
	}
	while (++i < len)
		sub[i] = s[i + (size_t)start];
	sub[i] = '\0';
	return (sub);
}
