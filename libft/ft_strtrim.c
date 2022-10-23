/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:04:38 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/31 18:15:49 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_valid(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		len;
	int		i;

	if (!set || !s1)
		return (NULL);
	while (check_valid(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && check_valid(*(s1 + len - 1), set))
		len--;
	new = malloc(len + 1);
	if (!new)
	{
		free(new);
		return (NULL);
	}
	i = -1;
	while (++i < len)
		new[i] = s1[i];
	new[i] = '\0';
	return (new);
}
