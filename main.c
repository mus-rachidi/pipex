/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:17:39 by murachid          #+#    #+#             */
/*   Updated: 2021/06/30 16:39:15 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int file_descriptor(char **av)
{
    char *s;
    int fd = open("/tmp/tmp1", O_CREAT | O_RDWR | O_TRUNC, 0644);
    while (1)
    {
        s = malloc(1024 * sizeof(char));
        write(1, "> ", 2);
        read(0, s, 1024);
        if ((strncmp(s, av[2], strlen(av[2])) == 0) && (s[strlen(av[2])] == '\0' || s[strlen(av[2]) ] == '\n'))
            break ;
        write(fd,s,strlen(s));
        free(s);
    }
   	close(fd);
    fd = open("/tmp/tmp1", O_RDONLY);
    return (fd);
}

int	ft_strcmp(char *s1, const char *s2)
{
	int x;

	x = 0;
	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0')
		x++;
	return (s1[x] - s2[x]);
}

int	main(int argc, char **argv, char **envs)
{
	int i = 2;
	int	last_fd;
	int nb = argc - 1;
	int fd;
	int nb_arg;
	nb_arg = 0;
	if(ft_strcmp(argv[1], "here_doc") == 0)
	{
		i++;
		fd = open(argv[nb], O_WRONLY | O_CREAT | O_APPEND, 0777);
		last_fd = file_descriptor(argv);
	}
	else
	{
		fd = open(argv[nb], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		last_fd = open(argv[1], O_RDONLY);
	}
	check_file(fd , last_fd);
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
	exec_(envs, head, last_fd, fd);
	return (0);
}
