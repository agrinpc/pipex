/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:44:10 by miahmadi          #+#    #+#             */
/*   Updated: 2022/04/06 16:12:53 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_condition(char *format, va_list vars)
{
	int	size;

	if (get_type(format) == 'c')
		size = print_char(format, va_arg(vars, int));
	if (get_type(format) == 's')
		size = print_string(format, va_arg(vars, char *));
	if (get_type(format) == 'd' || get_type(format) == 'i')
		size = print_int(format, va_arg(vars, int));
	if (get_type(format) == '%')
		size = print_string(format, "%");
	if (get_type(format) == 'u')
		size = print_uint(format, va_arg(vars, unsigned int));
	if (get_type(format) == 'x' || get_type(format) == 'X')
		size = print_hex(format, va_arg(vars, unsigned int),
				is_capital(get_type(format)));
	if (get_type(format) == 'p')
		size = print_hex(format, va_arg(vars, unsigned long int),
				is_capital(get_type(format)));
	return (size);
}

static int	return_ret(int *i, char *format, va_list vars)
{
	*i += (int)ft_strlen(format);
	return (ft_print_condition(format, vars));
}

int	ft_printf(const char *s, ...)
{
	char	*format;
	int		i;
	va_list	vars;
	int		sum;

	i = 0;
	sum = 0;
	va_start(vars, s);
	while (s[i])
	{
		while (s[i] && s[i] != '%')
		{
			write(1, &s[i], 1);
			i++;
			sum++;
		}
		format = get_format(s, i);
		if (s[i])
			sum += return_ret(&i, format, vars);
		if (format[0])
			free(format);
	}
	va_end(vars);
	return (sum);
}
