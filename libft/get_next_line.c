/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:31:14 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/17 17:01:26 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_res(char *strs[2],
			char tmp[OPEN_MAX][NUM_BUF + BUFFER_SIZE], int ints[3], int fd)
{
	if (ints[0] == 0)
	{
		ints[1] = 1;
		if (!strs[0] || !strs[0][0])
		{
			free(strs[0]);
			strs[0] = NULL;
		}
	}
	else
	{
		ints[1] = ret_nl_make_zero(strs[1], ints[0], 0);
		if (ints[1] < ints[0] - 1 && ints[1] >= 0)
		{
			ft_strtcpy(tmp[fd], strs[1], ints, 1);
			write_num(tmp[fd], ints[0] - ints[1] - 1);
			ints[0] = ints[1] + 1;
		}
		strs[0] = ft_gnl_strjoin(strs[0], strs[1], ints[2], ints[0]);
		ints[2] += ints[0];
	}
}

static int	initialize(char *strs[2], int ints[3], char cur[BUFFER_SIZE])
{
	ints[1] = -1;
	ints[2] = 0;
	strs[0] = malloc(1);
	if (!strs[0])
		return (0);
	strs[0][0] = 0;
	strs[1] = cur;
	return (1);
}

static char	*free_res(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			ints[3];
	static char	tmp[OPEN_MAX][NUM_BUF + BUFFER_SIZE];
	char		cur[BUFFER_SIZE];
	char		*strs[2];

	if (fd < 0 || read(fd, 0, 0) < 0 || !initialize(strs, ints, cur))
		return (NULL);
	while (ints[1] == -1)
	{
		ints[0] = read_num(tmp[fd]);
		if (ints[0] > 0)
		{
			ft_strtcpy(cur, tmp[fd], ints, 0);
			ret_nl_make_zero(tmp[fd], NUM_BUF + BUFFER_SIZE, 1);
		}
		else
			ints[0] = read(fd, cur, BUFFER_SIZE);
		if (ints[0] < 0)
			return (free_res(strs[0]));
		else
			get_res(strs, tmp, ints, fd);
	}
	return (strs[0]);
}
