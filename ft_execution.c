/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:56:12 by murachid          #+#    #+#             */
/*   Updated: 2021/06/30 16:11:06 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		exec_(char **envs, t_node *node, int last_fd, int fd)
{
	int fds[2];
	int pid;
	pipe(fds);
	pid = fork();
	if (!pid)
		ft_command_two(envs, fds, node, last_fd, fd);
	close(fds[1]);
	if (node->next)
		exec_(envs, node->next, fds[0], fd);
	close(fds[0]);
	waitpid(pid, NULL, 0);
	return (pid);
}

void	ft_command_two(char **envs, int *fd_pipe, t_node *node, int last_fd, int fd)
{
	char	**cmd;
	char	*temp;
	
	cmd = ft_split(node->data, ' ');
	temp = cmd[0];
	cmd[0] = ft_path(cmd[0], envs);
	free(temp);
	if(node->next)
		dup2(fd_pipe[1], 1);
	else
		dup2(fd, 1);
	if(last_fd)
		dup2(last_fd, 0);
	close(fd_pipe[1]);
	close(fd_pipe[0]);
	if(last_fd)
		close(last_fd);
	if(execvp(cmd[0], cmd) < 0)
	{
		printf("Could not execute command 2..\n");
		exit(0);
	}
}
