/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:22:46 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/30 18:07:59 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_size(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		i;
	char	*res;

	if (n == -2147483648)
		return (ft_memcpy(ft_calloc(12, sizeof(char)), "-2147483648", 12));
	sign = 1;
	if (n < 0)
		sign = -1;
	n = n * sign;
	i = get_int_size(n);
	res = ft_calloc(i + 1 + (2 - sign) / 3, sizeof(char));
	if (!res)
		return (NULL);
	if (sign < 0)
		res[0] = '-';
	else
		i--;
	while (n > 9)
	{
		res[i--] = n % 10 + 48;
		n = n / 10;
	}
	res[(2 - sign) / 3] = n + 48;
	return (res);
}
