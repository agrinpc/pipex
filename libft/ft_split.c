/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:23:59 by miahmadi          #+#    #+#             */
/*   Updated: 2022/10/20 23:45:00 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_elemnts(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i - 1] && s[i - 1] != c)
			j++;
	}
	return (j);
}

int	*get_elem_pos(char const *s, char c, int start)
{
	static int	elem[2];
	int			index;
	int			length;

	index = start;
	length = 0;
	while (s[index] && s[index] == c)
		index++;
	while (s[index + length] && s[index + length] != c)
		length++;
	elem[0] = index;
	elem[1] = length;
	return (elem);
}

void	create_result(char const *s, char c, int size, char **res)
{
	int		start;
	int		counter;
	int		*det;
	char	*elem;

	start = 0;
	counter = -1;
	while (++counter < size)
	{
		det = get_elem_pos(s, c, start);
		elem = ft_substr(s, det[0], det[1]);
		res[counter] = ft_calloc(ft_strlen(elem) + 1, 1);
		if (!res[counter])
			free(res[counter]);
		ft_strlcpy(res[counter], elem, ft_strlen(elem) + 1);
		free(elem);
		start = det[0] + det[1];
	}
	res[counter] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		size;

	if (!s)
		return (NULL);
	size = count_elemnts(s, c);
	res = ft_calloc(size + 1, sizeof(char *));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	create_result(s, c, size, res);
	return (res);
}
