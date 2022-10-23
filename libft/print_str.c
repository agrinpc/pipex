/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:48:30 by miahmadi          #+#    #+#             */
/*   Updated: 2022/04/04 20:42:07 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_string_con(char	*format, char *str, int x, int y)
{
	int	i;

	i = -1;
	if (!is_left_aligned(format))
	{
		while (++i < x - y)
		{
			if (is_zeroed(format))
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		i--;
		while (++i < x)
			write(1, &str[i - (x - y)], 1);
	}
	else
	{
		while (++i < y)
			write(1, &str[i], 1);
		i--;
		while (++i < x)
			write(1, " ", 1);
	}
	return (i);
}

int	print_string(char	*format, char *str)
{
	int	x;
	int	y;

	x = get_min(format);
	y = get_max(format);
	if (!str)
		str = "(null)";
	if (y > (int)ft_strlen(str) || y == -1)
		y = (int)ft_strlen(str);
	if (x == -1)
		x = (int)ft_strlen(str);
	if (x < y)
		x = y;
	return (print_string_con(format, str, x, y));
}
