/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:52:09 by miahmadi          #+#    #+#             */
/*   Updated: 2022/04/06 15:08:14 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	int		i;
	char	*res;

	i = get_uint_size(n);
	res = ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	else
		i--;
	while (n > 9)
	{
		res[i--] = n % 10 + 48;
		n = n / 10;
	}
	res[0] = n + 48;
	return (res);
}

int	is_what(char c)
{
	if (c == '%')
		return (3);
	if (c == 'i' || c == 'd' || c == 's' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'p' || c == 'c')
		return (2);
	if (c == '0' || c == '-' || c == '+' || c == ' ' || c == '#' || c == '.')
		return (1);
	return (0);
}

int	is_left_aligned(char *format)
{
	int	i;

	i = 0;
	while (format[i++])
		if (format[i] == '-')
			return (1);
	return (0);
}

int	is_blank(char *format, long int n)
{
	int	i;

	i = 0;
	if (n < 0)
		return (0);
	while (format[i++])
		if (format[i] == ' ')
			return (1);
	return (0);
}

int	is_plus(char *format)
{
	int	i;

	i = 0;
	while (format[i++])
		if (format[i] == '+')
			return (1);
	return (0);
}
