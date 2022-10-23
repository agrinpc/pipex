/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:04:17 by miahmadi          #+#    #+#             */
/*   Updated: 2022/10/24 01:41:34 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	do_normal_step_one(char **argv, char **envp, int pipes[2])
{
	int	fd_in;
	int	pid;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
	{
		error(strerror(errno), argv[1], errno);
		pipe(pipes);
	}
	else
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		pipe(pipes);
		pid = fork();
		if (pid == 0)
			exec_cmd1(envp, argv[2], pipes);
	}
}

int	do_normal(int argc, char **argv, char **envp)
{
	int	pipes[2];
	int	fd_out;
	int	pid;
	int	i;

	if (argc < 5)
		return (error(
				"Arguments: ",
				"<input_file> <cmd1> <cmd2> <cmd3> .... <ouput_file>",
				EINVAL));
	do_normal_step_one(argv, envp, pipes);
	i = 0;
	while (++i < argc - 4)
		loop(pipes, i, argv, envp);
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(pipes[0], STDIN_FILENO);
	close(pipes[0]);
	close(pipes[1]);
	pid = fork();
	if (pid == 0)
		exec_cmd2(envp, argv[argc - 2], fd_out, argv[argc - 1]);
	waitpid(pid, NULL, 2);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	ret;

	ret = 0;
	if (argc < 2)
		return (error("Arguments are not correct", "", EINVAL));
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
		ret = do_heredoc(argc, argv, envp);
	else
		ret = do_normal(argc, argv, envp);
	return (ret);
}
