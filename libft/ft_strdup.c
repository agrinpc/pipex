/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:57:43 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/29 20:04:54 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		size;
	char	*tmp;
	char	*s;

	size = 0;
	i = 0;
	while (src[size])
		size++;
	tmp = malloc(size + 1);
	if (!tmp)
		return (NULL);
	s = (char *)tmp;
	i = 0;
	while (i < size)
	{
		s[i] = src[i];
		i++;
	}
	s[size] = '\0';
	return (s);
}
