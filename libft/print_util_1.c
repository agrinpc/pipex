/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:49:28 by miahmadi          #+#    #+#             */
/*   Updated: 2022/04/06 15:10:36 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_max(char *format)
{
	int		i;
	int		j;
	int		ret;
	char	*str;

	i = 0;
	while (format[i] && format[i] != '.')
		i++;
	j = 1;
	while (format[i + j] && ft_isdigit(format[i + j]))
		j++;
	if (i + j == (int)ft_strlen(format) + 1)
		return (-1);
	str = ft_substr(format, i + 1, j - 1);
	ret = ft_atoi(str);
	free(str);
	return (ret);
}

char	get_type(char	*format)
{
	int	i;

	i = 1;
	while (format[i] && !(is_what(format[i]) == 2 || is_what(format[i]) == 3))
		i++;
	return (format[i]);
}

char	*get_sign_char(int n, char	*format)
{
	char	*numbers;

	if (n < 0)
		return ("-");
	if (n >= 0 && is_plus(format))
		return ("+");
	numbers = return_number(n, get_max(format));
	if (is_zeroed(format) && get_max(format) == -1
		&& (int)ft_strlen(numbers) < (int)get_min(format))
	{
		free(numbers);
		return ("0");
	}
	if (is_left_aligned(format) || (int)ft_strlen(numbers) >= get_min(format))
	{
		free(numbers);
		return (NULL);
	}
	free(numbers);
	return (NULL);
}

char	*get_hex_char(char *format, char *numbers)
{
	if ((is_hash(format) && get_type(format) == 'x'
			&& !(ft_strlen(numbers) == 1 && numbers[0] == '0'))
		|| get_type(format) == 'p')
		return ("0x");
	if (is_hash(format) && get_type(format) == 'X'
		&& !(ft_strlen(numbers) == 1 && numbers[0] == '0'))
		return ("0X");
	if (is_left_aligned(format) || ((int)ft_strlen(numbers) >= get_min(format)))
		return (NULL);
	if (is_zeroed(format) && get_max(format) == -1)
		return ("0");
	return (NULL);
}

long	get_abs(long num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
