/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:55:48 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/29 16:27:17 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*s;
	size_t	n;

	n = number * size;
	if (n == 0)
		n = 1;
	s = malloc(n);
	if (s)
		ft_bzero(s, n);
	return (s);
}
