/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:47:35 by miahmadi          #+#    #+#             */
/*   Updated: 2022/10/17 01:18:02 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (!(unsigned int)s2[i] && !(unsigned int)s1[i])
			return (0);
		if ((unsigned int)s2[i] && !(unsigned int)s1[i])
			return (-1);
		if (!(unsigned int)s2[i] && (unsigned int)s1[i])
			return (1);
		if ((unsigned int)s1[i] > (unsigned int)s2[i])
			return (1);
		else if ((unsigned int)s1[i] < (unsigned int)s2[i])
			return (-1);
		i++;
	}
	return (0);
}
