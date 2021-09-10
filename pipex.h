/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:50:29 by murachid          #+#    #+#             */
/*   Updated: 2021/06/03 09:30:06 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex
{
	char	*bin;
	char	*temp;
	char	*path;
	int		fd;
	char	**path_split;

}t_pipex;

void		ft_command_one(char **argv, char **envs, int *fd_p, int *fd);
void		ft_command_two(char **argv, char **envs, int *fd_p, int *fd);
void		exec_cmd(char **cmd, char *envs[]);
char		*getenv_new(char **envs);
char		*ft_path(char *cmd, char **envs);
size_t		ft_strlen(const char *str);
void		free_array(char **array);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);

#endif
