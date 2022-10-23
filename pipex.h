/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:44:46 by miahmadi          #+#    #+#             */
/*   Updated: 2022/10/23 19:20:47 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include "./libft/libft.h"

int		do_heredoc(int argc, char **argv, char **envp);
int		error(char *msg, char *extra, int err);
char	*find_exe(char **envp, char *cmd);
void	exec_cmd1(char **envp, char *cmd, int pipes[2]);
void	exec_cmd2(char **envp, char *cmd, int fd_out, char *file);
void	loop(int pipes[2], int i, char **argv, char **envp);

#endif
