/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:24:29 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/31 11:52:57 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	l;

	l = 0;
	i = -1;
	while (src[l])
		l++;
	if (n == 0)
		return (l);
	while (++i < n - 1 && i < l)
		dest[i] = src[i];
	dest[i] = 0;
	return (l);
}
