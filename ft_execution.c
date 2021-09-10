/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:35:43 by murachid          #+#    #+#             */
/*   Updated: 2021/06/10 10:48:34 by murachid         ###   ########.fr       */
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

void	ft_command_one(char **argv, char **envs, int *fd_p, int *fd)
{
	char	**cmd;
	char	*temp;

	if (fd[0] != -1)
	{
		cmd = ft_split(argv[2], ' ');
		temp = cmd[0];
		if (check_path_exist(cmd[0]) == 0)
			cmd[0] = ft_path(cmd[0], envs);
		free(temp);
		close(fd_p[0]);
		dup2(fd_p[1], 1);
		dup2(fd[0], 0);
		execve(cmd[0], cmd, envs);
		perror("pipex:");
	}
}

void	ft_command_two(char **argv, char **envs, int *fd_p, int *fd)
{
	char	**cmd;
	char	*temp;

	cmd = ft_split(argv[3], ' ');
	temp = cmd[0];
	if (check_path_exist(cmd[0]) == 0)
		cmd[0] = ft_path(cmd[0], envs);
	free(temp);
	close(fd_p[1]);
	dup2(fd_p[0], 0);
	dup2(fd[1], 1);
	execve(cmd[0], cmd, envs);
	perror("pipex:");
}
