/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:03:59 by murachid          #+#    #+#             */
/*   Updated: 2021/07/05 16:56:58 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	file_descriptor(char **av)
{
	char	*s;
	int		res;
	int		fd;

	fd = open("/tmp/tmp1", O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		s = malloc(1024 * sizeof(char));
		write(1, "> ", 2);
		res = read(0, s, 1024);
		s[res] = 0;
		if ((ft_strncmp(s, av[2], ft_strlen(av[2])) == 0)
			&& (s[ft_strlen(av[2])] == '\0'
				|| s[ft_strlen(av[2])] == '\n'))
			break ;
		write(fd, s, ft_strlen(s));
		free(s);
	}
	free(s);
	close(fd);
	fd = open("/tmp/tmp1", O_RDONLY);
	return (fd);
}
