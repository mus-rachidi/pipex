/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:17:39 by murachid          #+#    #+#             */
/*   Updated: 2021/07/04 17:04:48 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envs)
{
	int i;
	int	int_fd;
	int nb = argc - 1;
	int out_fd;
	int nb_arg;
	nb_arg = 0;
	i = 2;
	if(ft_strcmp(argv[1], "here_doc") == 0)
	{
		i++;
		out_fd = open(argv[nb], O_WRONLY | O_CREAT | O_APPEND, 0777);
		int_fd = file_descriptor(argv);
	}
	else
	{
		out_fd = open(argv[nb], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		int_fd = open(argv[1], O_RDONLY);
	}
	check_file(out_fd , int_fd);
	t_node *head = NULL;
	while(i < argc - 1)
	{
		append(&head, argv[i]);
		i++;
		nb_arg++;
	}
	if(nb_arg < 2)
	{
		perror("pipex");
		exit(1);
	}
	exec_(envs, head, int_fd, out_fd);
	return (0);
}
