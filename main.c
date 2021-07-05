/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:17:39 by murachid          #+#    #+#             */
/*   Updated: 2021/07/05 17:00:09 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_fd	check_fd_file(char **argv, int argc, t_fd *fd)
{
	int	nb;

	nb = argc - 1;
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		fd->check_fd++;
		fd->out_fd = open(argv[nb], O_WRONLY | O_CREAT | O_APPEND, 0777);
		fd->int_fd = file_descriptor(argv);
	}
	else
	{
		fd->out_fd = open(argv[nb], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		fd->int_fd = open(argv[1], O_RDONLY);
	}
	check_file(fd);
	return (*fd);
}

int	main(int argc, char **argv, char **envs)
{
	int		nb_arg;
	t_fd	fd;
	t_node	*head;

	nb_arg = 0;
	fd.check_fd = 2;
	if(argc < 6)
		error_message();
	fd = check_fd_file(argv, argc, &fd);
	head = NULL;
	while (fd.check_fd < argc - 1)
	{
		append(&head, argv[fd.check_fd]);
		fd.check_fd++;
		nb_arg++;
	}
	if (nb_arg < 2)
	{
		perror("pipex");
		exit(1);
	}
	exec_pipe(envs, head, &fd);
	return (0);
}
