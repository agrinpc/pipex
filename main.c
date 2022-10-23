/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:44:33 by miahmadi          #+#    #+#             */
/*   Updated: 2022/10/24 01:41:50 by miahmadi         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	int	pipes[2];
	int	fd_out;
	int	pid;

	if (argc != 5)
		return (error("Number of arguments should be 4",
				"input_file cmd1 cm2 ouput_file", EINVAL));
	do_normal_step_one(argv, envp, pipes);
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
