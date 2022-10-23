/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:48:00 by miahmadi          #+#    #+#             */
/*   Updated: 2022/04/06 15:35:18 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	check_zero(char *format, long num)
{
	if (is_zeroed(format) && get_max(format) == -1)
	{
		if (get_sign_char(num, format))
			write(1, get_sign_char(num, format), 1);
		return ('0');
	}
	return (' ');
}

int	print_int_con_1(char *format, long num, int x, int y)
{
	int		i;
	char	*numbers;
	int		sum;

	numbers = return_number(num, get_max(format));
	i = -1;
	sum = 0;
	if (get_sign_char(num, format))
		write(1, get_sign_char(num, format),
			ft_strlen(get_sign_char(num, format)));
	while (++i < y - (int)ft_strlen(numbers))
		write(1, "0", 1);
	sum += i;
	i = -1;
	while (++i < (int)ft_strlen(numbers))
		write(1, &numbers[i], 1);
	sum += i;
	i = -1;
	if (is_plus(format) || num < 0)
		x--;
	while (++i < x - y)
		write(1, " ", 1);
	free(numbers);
	return (i + sum + (int)ft_strlen(get_sign_char(num, format)));
}

int	print_int_con_2(char *format, long num, int x, int y)
{
	int		i;
	char	*numbers;
	char	c;
	int		sum;

	i = -1;
	sum = 0;
	numbers = return_number(num, get_max(format));
	c = check_zero(format, num);
	while (++i < x - y - (int)ft_strlen(get_sign_char(num, format)))
		write(1, &c, 1);
	if (!is_zeroed(format) || get_max(format) != -1)
		write(1, get_sign_char(num, format), 1);
	sum += i;
	i = -1;
	while (++i < y - (int)ft_strlen(numbers))
		write(1, "0", 1);
	sum += i;
	i = -1;
	while (++i < (int)ft_strlen(numbers))
		write(1, &numbers[i], 1);
	free(numbers);
	return (i + sum + (int)ft_strlen(get_sign_char(num, format)));
}

int	print_int(char *format, long num)
{
	int		x;
	int		y;
	int		i;
	char	*numbers;

	numbers = return_number(num, get_max(format));
	x = get_min(format);
	y = get_max(format);
	if (y < 0 || y < (int)ft_strlen(numbers))
		y = (int)ft_strlen(numbers);
	if (is_blank(format, num))
	{
		write(1, " ", 1);
		x--;
	}
	i = is_blank(format, num);
	if (is_left_aligned(format))
		i += print_int_con_1(format, num, x, y);
	else
		i += print_int_con_2(format, num, x, y);
	free(numbers);
	return (i);
}
