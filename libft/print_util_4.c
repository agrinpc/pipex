/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:53:23 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/30 16:57:41 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_uint_size(unsigned int n)
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

int	get_hex_size(unsigned long int a)
{
	int	size;

	if (a == 0)
		return (1);
	size = 0;
	while (a > 0 && ++size)
		a = a / 16;
	return (size);
}

char	*get_hex(unsigned long a, int size, int is_big, int max)
{
	char	*hex;

	if (a == 0 && max == 0)
	{
		hex = malloc(0);
		if (!hex)
			return (NULL);
		ft_strlcpy(hex, "", 0);
		return (hex);
	}
	hex = malloc(size + 1);
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (--size > -1)
	{
		if (is_big)
			hex[size] = "0123456789ABCDEF"[a % 16];
		else
			hex[size] = "0123456789abcdef"[a % 16];
		a /= 16;
	}
	return (hex);
}

char	*return_number(long num, int max)
{
	char	*res;

	if (num == -2147483648)
	{
		res = malloc(10);
		if (!res)
			return (NULL);
		ft_strlcpy(res, "2147483648", 11);
		return (res);
	}
	else if (num == 0 && max == 0)
	{
		res = malloc(0);
		if (!res)
			return (NULL);
		ft_strlcpy(res, "", 0);
		return (res);
	}
	return (ft_itoa(get_abs(num)));
}

char	*return_unumber(unsigned int num, int max)
{
	char	*res;

	if (num == 0 && max == 0)
	{
		res = malloc(0);
		if (!res)
			return (NULL);
		ft_strlcpy(res, "", 0);
		return (res);
	}
	return (ft_utoa(num));
}
