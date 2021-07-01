/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:50:29 by murachid          #+#    #+#             */
/*   Updated: 2021/06/30 15:21:49 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
#include <string.h>
#include <sys/wait.h>
typedef struct s_pipex
{
	char	*bin;
	char	*temp;
	char	*path;
	int		fd;
	char	**path_split;
}t_pipex;

typedef struct s_node
{	
	char			*data;
	struct s_node	*next;
}t_node;

int		exec_(char **envs, t_node *node, int last_fd, int fd);
void	append(t_node **head_ref, char *new_data);
void	ft_command_two(char **envs, int *fd_pipe, t_node *node, int last_fd, int fd);
void	exec_cmd(char **cmd, char *envs[]);
char	*getenv_new(char **envs);
char	*ft_path(char *cmd, char **envs);
size_t	ft_strlen(const char *str);
void	free_array(char **array);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
void	check_file(int fd, int fd_last);

#endif
