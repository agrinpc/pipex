/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:51:21 by miahmadi          #+#    #+#             */
/*   Updated: 2022/10/24 01:39:04 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error(char *msg, char *extra, int err)
{
	int		i;
	char	*err_str1;
	char	*err_str2;

	err_str1 = ft_strjoin(msg, ": ");
	err_str2 = ft_strjoin(err_str1, extra);
	free(err_str1);
	write(2, "Error: ", 7);
	i = -1;
	while (err_str2[++i])
		write(2, &err_str2[i], 1);
	free(err_str2);
	write(2, "\n", 1);
	return (err);
}

char	*find_exe(char **envp, char *cmd)
{
	int		i;
	char	**all_path;
	char	*bash;

	i = -1;
	while (cmd[++i])
		if (cmd[i] == ' ')
			cmd[i] = '\0';
	i = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "PATH=", 5))
			all_path = ft_split(ft_substr(envp[i], 5, ft_strlen(envp[i])), ':');
	i = -1;
	while (all_path[++i])
	{
		bash = ft_strjoin(ft_strjoin(all_path[i], "/"), cmd);
		if (access(bash, F_OK) == 0)
			return (bash);
	}
	return (NULL);
}

void	exec_cmd1(char **envp, char *cmd, int pipes[2])
{
	char	*exe;
	char	**cmd_args;

	if (!cmd[0] || cmd[0] == ' ')
	{
		error("command not found", cmd, errno);
		exit(errno);
	}
	cmd_args = ft_split(cmd, ' ');
	exe = find_exe(envp, cmd);
	dup2(pipes[1], STDOUT_FILENO);
	close(pipes[1]);
	if (!exe)
	{
		error("command not found", cmd, errno);
		exit(errno);
	}
	execve(exe, cmd_args, envp);
}

void	exec_cmd2(char **envp, char *cmd, int fd_out, char *file)
{
	char	*exe;
	char	**cmd_args;

	exe = NULL;
	if (!cmd[0])
		error("command not found", "", errno);
	if (cmd[0] == ' ')
		error("command not found", cmd, errno);
	cmd_args = ft_split(cmd, ' ');
	exe = find_exe(envp, cmd);
	if (!exe)
		error("command not found", cmd, errno);
	if (fd_out < 0)
		error("permission denied", file, EACCES);
	if (!exe || fd_out < 0 || !cmd[0] || cmd[0] == ' ')
		exit(errno);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	execve(exe, cmd_args, envp);
}

void	loop(int pipes[2], int i, char **argv, char **envp)
{
	int	pid;

	if (pipes[0] != -1)
	{
		dup2(pipes[0], STDIN_FILENO);
		close(pipes[0]);
		close(pipes[1]);
	}
	pipe(pipes);
	pid = fork();
	if (pid == 0)
		exec_cmd1(envp, argv[i + 2], pipes);
}
