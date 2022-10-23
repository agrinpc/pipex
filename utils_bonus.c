/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:47:59 by miahmadi          #+#    #+#             */
/*   Updated: 2022/10/24 01:56:10 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	heredoc_check(char *elm, char **str, char **cur_str, int *readline)
{
	if (ft_strncmp(elm, *cur_str, ft_strlen(elm)) == 0
		&& ft_strlen(elm) == ft_strlen(*cur_str) - 1)
	{
		(*readline) = -1;
		free(*cur_str);
	}
	else
	{
		*str = ft_strjoin_2(*str, *cur_str);
		write(0, "heredoc> ", 9);
		*cur_str = ft_calloc(1, 1);
	}
}

static char	*heredoc(char **argv)
{
	int		readline;
	char	cur[2];
	char	*cur_str;
	char	*str;

	readline = 1;
	cur[1] = 0;
	str = ft_calloc(1, 1);
	cur_str = ft_calloc(1, 1);
	write(1, "heredoc> ", 9);
	while (readline > 0)
	{
		readline = read(0, &cur, 1);
		if (readline > -1)
		{
			cur_str = ft_strjoin_1(cur_str, cur);
			if (cur[0] == '\n')
				heredoc_check(argv[2], &str, &cur_str, &readline);
		}
	}
	return (str);
}

static void	do_heredoc_step_1(char **argv, char **envp, int pipes[2], char *str)
{
	int		tmp[2];
	int		pid;

	pipe(tmp);
	write(tmp[1], str, ft_strlen(str));
	free(str);
	pipe(pipes);
	dup2(tmp[0], STDIN_FILENO);
	close(tmp[0]);
	close(tmp[1]);
	pid = fork();
	if (pid == 0)
		exec_cmd1(envp, argv[3], pipes);
	waitpid(pid, NULL, 2);
}

int	do_heredoc(int argc, char **argv, char **envp)
{
	int		pipes[2];
	int		fd_out;
	int		pid;
	char	*str;

	if (argc != 6)
		return (error(
				"Arguments: ",
				"<here_doc> <LIMITER> <cmd> <cmd1> <ouput_file>",
				EINVAL));
	str = heredoc(argv);
	do_heredoc_step_1(argv, envp, pipes, str);
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(pipes[0], STDIN_FILENO);
	close(pipes[0]);
	close(pipes[1]);
	pid = fork();
	if (pid == 0)
		exec_cmd2(envp, argv[argc - 2], fd_out, "");
	waitpid(pid, NULL, 2);
	return (0);
}
