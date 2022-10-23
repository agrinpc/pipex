/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:51:04 by miahmadi          #+#    #+#             */
/*   Updated: 2022/04/06 15:07:57 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_zeroed(char *format)
{
	int	i;

	i = 0;
	while (format[i] && (!ft_isdigit(format[i]) || format[i] == '0'))
	{
		if (format[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int	is_capital(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_hash(char *format)
{
	int	i;

	i = 0;
	while (format[i++])
		if (format[i] == '#')
			return (1);
	return (0);
}

char	*get_format(const char *s, int i)
{
	int		j;

	j = 0;
	while (s[i + j] && (is_what(s[i + j]) || ft_isdigit(s[i + j])))
	{
		j++;
		if (is_what(s[i + j]) == 2 || is_what(s[i + j]) == 3)
			return (ft_substr(s, i, j + 1));
	}
	return ("");
}

int	get_min(char *format)
{
	int		i;
	int		j;
	int		ret;
	char	*str;

	i = 0;
	while (format[i] && (!ft_isdigit(format[i]) || format[i] == '0'))
	{
		if (format[i] == '.')
			return (0);
		i++;
	}
	j = 0;
	while (format[i + j] && ft_isdigit(format[i + j]))
		j++;
	if (i + j == (int)ft_strlen(format))
		return (-1);
	str = ft_substr(format, i, j);
	ret = ft_atoi(str);
	free(str);
	return (ret);
}
