/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:46:22 by miahmadi          #+#    #+#             */
/*   Updated: 2022/04/05 15:54:27 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char_con(char	*format, char c, int x, int y)
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
		write(1, &c, 1);
	}
	else
	{
		while (++i < y)
			write(1, &c, 1);
		i--;
		while (++i < x)
			write(1, " ", 1);
		i--;
	}
	i++;
	return (i);
}

int	print_char(char *format, char c)
{
	int	x;
	int	y;

	x = get_min(format);
	y = get_max(format);
	if (y > 1 || y == -1)
		y = 1;
	if (x == -1)
		x = 1;
	if (x < y)
		x = y;
	return (print_char_con(format, c, x, y));
}
