/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:33:34 by miahmadi          #+#    #+#             */
/*   Updated: 2022/04/06 15:35:28 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	check_zero(char	*format, char *numbers)
{
	if (is_zeroed(format) && get_max(format) == -1)
	{
		write(1, get_hex_char(format, numbers),
			ft_strlen(get_hex_char(format, numbers)));
		return ('0');
	}
	return (' ');
}

int	print_hex_con_1(char *format, char *numbers, int x, int y)
{
	int	i;
	int	sum;

	i = -1;
	sum = 0;
	write(1, get_hex_char(format, numbers),
		ft_strlen(get_hex_char(format, numbers)));
	while (++i < y - (int)ft_strlen(numbers))
		write(1, "0", 1);
	sum += (i);
	i = -1;
	while (++i < (int)ft_strlen(numbers))
		write(1, &numbers[i], 1);
	sum += (i);
	i = -1;
	while (++i < x - y - (int)ft_strlen(get_hex_char(format, numbers)))
		write(1, " ", 1);
	return (i + sum + ft_strlen(get_hex_char(format, numbers)));
}

int	print_hex_con_2(char *format, char *numbers, int x, int y)
{
	int		i;
	char	c;
	int		sum;

	i = -1;
	sum = 0;
	c = check_zero(format, numbers);
	while (++i < x - y - (int)ft_strlen(get_hex_char(format, numbers)))
		write(1, &c, 1);
	if (!is_zeroed(format) || get_max(format) != -1)
		write(1, get_hex_char(format, numbers),
			ft_strlen(get_hex_char(format, numbers)));
	sum += i;
	i = -1;
	while (++i < y - (int)ft_strlen(numbers))
		write(1, "0", 1);
	sum += i;
	i = -1;
	while (++i < (int)ft_strlen(numbers))
		write(1, &numbers[i], 1);
	return (i + sum + ft_strlen(get_hex_char(format, numbers)));
}

int	print_hex(char *format, unsigned long int num, int is_big)
{
	int		x;
	int		y;
	int		i;
	char	*numbers;

	numbers = get_hex(num, get_hex_size(num), is_big, get_max(format));
	x = get_min(format);
	y = get_max(format);
	if (y == -1 || y < (int)ft_strlen(numbers))
		y = (int)ft_strlen(numbers);
	i = 0;
	if (is_left_aligned(format))
		i += print_hex_con_1(format, numbers, x, y);
	else
	{
		i += print_hex_con_2(format, numbers, x, y);
	}
	free(numbers);
	return (i);
}
