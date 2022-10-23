/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:14:01 by miahmadi          #+#    #+#             */
/*   Updated: 2022/04/02 17:21:53 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c1;
	char	*s1;

	i = 0;
	c1 = (char)c;
	s1 = (char *)s;
	while (s1[i])
		i++;
	i++;
	while (i--)
		if (s1[i] == c1)
			return (s1 + i);
	return (0);
}
