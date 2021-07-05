/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:50:03 by murachid          #+#    #+#             */
/*   Updated: 2021/07/05 16:29:27 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(void)
{
	perror("pipex");
	exit(1);
}

void	check_file(t_fd *fd)
{
	if (fd->out_fd == -1)
		error_message();
	if (fd->int_fd == -1)
	{
		perror("pipex");
		close(fd->int_fd);
	}
	if (fd->out_fd == -1 && fd->int_fd == -1)
		exit(1);
}

void	append(t_node **head_ref, char *new_data)
{
	t_node	*new_node;
	t_node	*last;

	last = *head_ref;
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return ;
}
