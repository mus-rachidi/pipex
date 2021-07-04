/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:56:12 by murachid          #+#    #+#             */
/*   Updated: 2021/07/04 17:02:10 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		exec_(char **envs, t_node *node, int last_fd, int out_fd)
{
	int fd_pipe[2];
	int pid;
	pipe(fd_pipe);
	pid = fork();
	if (!pid)
		ft_command_two(envs, fd_pipe, node, last_fd, out_fd);
	close(fd_pipe[1]);
	if (node->next)
		exec_(envs, node->next, fd_pipe[0], out_fd);
	close(fd_pipe[0]);
	waitpid(pid, NULL, 0);
	return (pid);
}

void	ft_command_two(char **envs, int *fd_pipe, t_node *node, int int_fd, int out_fd)
{
	char	**cmd;
	char	*temp;
	
	cmd = ft_split(node->data, ' ');
	temp = cmd[0];
	cmd[0] = ft_path(cmd[0], envs);
	free(temp);
	if (int_fd == -1)
		exit(1);
	if(node->next)
		dup2(fd_pipe[1], 1);
	else
		dup2(out_fd, 1);
	if(int_fd)
		dup2(int_fd, 0);
	if(execvp(cmd[0], cmd) < 0)
	{
		printf("Could not execute command 2..\n");
		exit(0);
	}
}
