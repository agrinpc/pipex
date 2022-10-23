/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:15:39 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/30 11:35:01 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		size;
	int		i;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size)
		res[i] = (*f)(i, s[i]);
	res[i] = '\0';
	return (res);
}
