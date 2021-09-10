/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:50:03 by murachid          #+#    #+#             */
/*   Updated: 2021/06/10 10:48:34 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file(int *fd)
{
	if (fd[1] == -1)
	{
		perror("pipex:");
		exit(1);
	}
	if (fd[0] == -1)
		perror("pipex:");
	if (fd[1] == -1 && fd[0] == -1)
		exit(1);
}

void	check_args(int argc)
{
	if (argc != 5)
	{
		perror("pipex:");
		exit(1);
	}
}

int	main(int argc, char **argv, char **envs)
{
	int	fd[2];
	int	fd_p[2];
	int	pid;

	check_args(argc);
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	check_file(fd);
	if (pipe(fd_p) == -1)
		perror("pipex:");
	pid = fork();
	if (pid < 0)
	{
		perror("pipex:");
		return (0);
	}
	if (pid == 0)
		ft_command_one (argv, envs, fd_p, fd);
	else
		ft_command_two (argv, envs, fd_p, fd);
	return (0);
}
