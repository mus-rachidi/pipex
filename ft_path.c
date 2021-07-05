/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:34:19 by murachid          #+#    #+#             */
/*   Updated: 2021/07/05 16:30:39 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getenv_new(char **envs)
{
	int	i;

	i = 0;
	while (envs[i++] != NULL)
	{
		if (ft_strncmp(envs[i], "PATH=", 5) == 0)
			return (ft_strdup(&envs[i][5]));
	}
	return (0);
}

void	error_check(char *path)
{
	if (!path)
	{
		perror("pipex");
		exit(1);
	}
}

void	ft_join(t_pipex *pipex, char *cmd)
{
	int		i;

	i = 0;
	pipex->path_split = ft_split(pipex->path, ':');
	while (pipex->path_split[i])
	{
		pipex->bin = ft_strdup(pipex->path_split[i]);
		pipex->temp = pipex->bin;
		pipex->bin = ft_strjoin(pipex->bin, "/");
		free(pipex->temp);
		pipex->temp = pipex->bin;
		pipex->bin = ft_strjoin(pipex->bin, cmd);
		free(pipex->temp);
		pipex->fd = open(pipex->bin, O_RDONLY);
		if (pipex->fd != -1)
			break ;
		else
		{
			free(pipex->bin);
			pipex->bin = NULL;
		}
		i++;
	}
	if (pipex->fd == -1)
		perror("pipex");
}

char	*ft_path(char *cmd, char **envs)
{
	t_pipex	pipex;

	pipex.path = getenv_new(envs);
	error_check(pipex.path);
	if (cmd)
	{
		ft_join(&pipex, cmd);
		free_array(pipex.path_split);
		free(pipex.path);
		cmd = pipex.bin;
		return (pipex.bin);
	}
	else
	{
		perror("pipex");
		exit(1);
	}
}
