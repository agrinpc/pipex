/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:20:46 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/30 18:16:40 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = -1;
	s1 = (char *)dest;
	s2 = (char *)src;
	if (s1 == s2)
		return (dest);
	if (s2 > s1)
	{
		while (++i < n)
			s1[i] = s2[i];
		return (dest);
	}
	while (++i < n)
		s1[n - i - 1] = s2[n - i - 1];
	return (dest);
}
