/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:37:09 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/20 23:31:01 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_strjoin(char *s1, char *s2, int size_s1, int size_s2)
{
	char	*new;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	new = malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < size_s1)
		new[i] = s1[i];
	i--;
	while (++i < size_s1 + size_s2)
		new[i] = s2[i - size_s1];
	new[i] = '\0';
	free(s1);
	return (new);
}

int	read_num(char *tmp)
{
	int	res;
	int	i;

	res = 0;
	if (tmp[0] < 0 || tmp[0] > 9)
		return (res);
	i = 0;
	while (tmp[i] > -1 && i < NUM_BUF)
	{
		res = res * 10 + tmp[i];
		i++;
	}
	return (res);
}

void	write_num(char *tmp, int num)
{
	int	i;
	int	max;

	max = 1;
	while ((num / max) > 9)
		max *= 10;
	if (num < 1)
		return ;
	i = 0;
	while (i < NUM_BUF && max > 1)
	{
		tmp[i] = (num / max);
		num = num % max;
		max = max / 10;
		i++;
	}
	tmp[i] = num;
	tmp[i + 1] = -1;
}

void	ft_strtcpy(char *dest, char *src, int ints[3], int mod)
{
	int	c;

	if (mod == 1)
	{
		c = ints[1];
		while (++c < ints[0])
			dest[c - ints[1] - 1 + NUM_BUF] = src[c];
	}
	else
	{
		c = -1;
		while (++c < ints[0])
			dest[c] = src[c + NUM_BUF];
	}
}

int	ret_nl_make_zero(char *cur, int ret, int mod)
{
	int	i;

	i = -1;
	if (mod == 0)
	{
		while (++i < ret && cur[i])
			if (cur[i] == '\n')
				return (i);
	}
	else
	{
		while (++i < ret)
			cur[i] = 0;
	}
	return (-1);
}
