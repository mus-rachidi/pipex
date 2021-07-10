/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:56:12 by murachid          #+#    #+#             */
/*   Updated: 2021/07/08 17:55:41 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_path_exist(char *path)
{
	int	fd;

	fd = 0;
	if (path)
	{
		if (path[0] == '/')
		{
			fd = open(path, O_RDONLY);
			if (fd)
			{
				close(fd);
				return (1);
			}
		}
		close(fd);
	}
	return (0);
}

void	exec_pipe(char **envs, t_node *node, t_fd *fd, int argc)
{
	int	fd_pipe[2];
	int	pid;
	int	status;

	while (fd->check_fd < argc - 1)
	{
		if (pipe(fd_pipe) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (!pid)
			ft_command_two(envs, fd_pipe, node, fd);
		close(fd_pipe[1]);
		if (node->next)
		{
			fd->int_fd = fd_pipe[0];
			node = node->next;
		}
		fd->check_fd++;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			fd->es = WEXITSTATUS(status);
	}
	exit(fd->es);
}

void	ft_command_two(char **envs, int *fd_pipe, t_node *node, t_fd *fd)
{
	char	**cmd;
	char	*temp;

	cmd = ft_split(node->data, ' ');
	temp = cmd[0];
	if (check_path_exist(cmd[0]) == 0)
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
	close(fd->int_fd);
	close(fd->out_fd);
	close(fd_pipe[0]);
	if (execvp(cmd[0], cmd) < 0)
		error_message();
}
