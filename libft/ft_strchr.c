/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:10:58 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/25 20:39:11 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c1;
	char	*s1;

	i = 0;
	c1 = (char)c;
	s1 = (char *)s;
	while (s1[i])
	{
		if (s1[i] == c1)
			return ((s1 + i));
		i++;
	}
	if (s1[i] == c1)
		return ((s1 + i));
	return (0);
}
