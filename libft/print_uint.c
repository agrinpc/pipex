/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:47:18 by miahmadi          #+#    #+#             */
/*   Updated: 2022/04/06 15:19:29 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_uint_con_1(char *numbers, int x, int y)
{
	int	i;
	int	sum;

	i = -1;
	sum = 0;
	while (++i < y - (int)ft_strlen(numbers))
		write(1, "0", 1);
	sum += i;
	i = -1;
	while (++i < (int)ft_strlen(numbers))
		write(1, &numbers[i], 1);
	sum += i;
	i = -1;
	while (++i < x - y)
		write(1, " ", 1);
	return (i + sum);
}

int	print_uint_con_2(char *format, char *numbers, int x, int y)
{
	int		i;
	char	c;
	int		sum;

	sum = 0;
	i = -1;
	c = ' ';
	if (is_zeroed(format) && get_max(format) == -1)
		c = '0';
	while (++i < x - y)
		write(1, &c, 1);
	sum += i;
	i = -1;
	while (++i < y - (int)ft_strlen(numbers))
		write(1, "0", 1);
	sum += i;
	i = -1;
	while (++i < (int)ft_strlen(numbers))
		write(1, &numbers[i], 1);
	return (i + sum);
}

int	print_uint(char *format, unsigned int num)
{
	int		x;
	int		y;
	int		i;
	char	*numbers;

	numbers = return_unumber(num, get_max(format));
	x = get_min(format);
	y = get_max(format);
	if (y == -1 || y < (int)ft_strlen(numbers))
		y = (int)ft_strlen(numbers);
	if (is_blank(format, num))
	{
		write(1, " ", 1);
		x--;
	}
	i = 0;
	if (is_left_aligned(format))
		i += print_uint_con_1(numbers, x, y);
	else
		i += print_uint_con_2(format, numbers, x, y);
	free(numbers);
	return (i);
}
