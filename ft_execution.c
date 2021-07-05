/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:56:12 by murachid          #+#    #+#             */
/*   Updated: 2021/07/05 16:46:38 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_pipe(char **envs, t_node *node, t_fd *fd)
{
	int	fd_pipe[2];
	int	pid;

	pipe(fd_pipe);
	pid = fork();
	if (!pid)
		ft_command_two(envs, fd_pipe, node, fd);
	close(fd_pipe[1]);
	if (node->next)
	{
		fd->int_fd = fd_pipe[0];
		exec_pipe(envs, node->next, fd);
	}
	close(fd_pipe[0]);
	waitpid(pid, NULL, 0);
	return (pid);
}

void	ft_command_two(char **envs, int *fd_pipe, t_node *node, t_fd *fd)
{
	char	**cmd;
	char	*temp;

	cmd = ft_split(node->data, ' ');
	temp = cmd[0];
	cmd[0] = ft_path(cmd[0], envs);
	free(temp);
	if (fd->int_fd == -1)
		exit(1);
	if (node->next)
		dup2(fd_pipe[1], 1);
	else
		dup2(fd->out_fd, 1);
	if (fd->int_fd)
		dup2(fd->int_fd, 0);
	if (execvp(cmd[0], cmd) < 0)
		error_message();
}
