/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:36:36 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/31 11:53:36 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	sized;
	size_t	sizes;
	size_t	i;

	sized = 0;
	sizes = 0;
	i = -1;
	while (dest[sized] && sized < n)
		sized++;
	while (src[sizes])
		sizes++;
	if (n <= sized)
		return (n + sizes);
	while (++i < n - sized - 1 && i < sizes)
		dest[sized + i] = src[i];
	dest[sized + i] = 0;
	return (sized + sizes);
}
