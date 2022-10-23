/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:24:24 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/31 18:10:26 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		size;
	int		i;

	if (!s || !f)
		return ;
	size = ft_strlen(s);
	i = -1;
	while (++i < size)
		(*f)(i, &s[i]);
}
