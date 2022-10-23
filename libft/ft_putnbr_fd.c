/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:53:58 by miahmadi          #+#    #+#             */
/*   Updated: 2022/03/30 18:14:00 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(int i)
{
	int	n;

	n = 1;
	while (i)
	{
		n *= 10;
		i--;
	}
	return (n);
}

static int	get_lenght(int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		size;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	size = get_lenght(n);
	while (size)
	{
		size--;
		c = n / power(size) + 48;
		n = n % power(size);
		write(fd, &c, 1);
	}
}
