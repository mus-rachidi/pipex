/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:50:03 by murachid          #+#    #+#             */
/*   Updated: 2021/07/04 17:09:00 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error_message()
{
	perror("pipex");
	exit(1);
}

void	check_file(int fd, int fd_last)
{
	if (fd == -1)
		error_message();
	if (fd_last == -1)
	{
		perror("pipex");
		close(fd_last);
	}
	if (fd == -1 && fd_last == -1)
		exit(1);
}

void append(t_node **head_ref, char *new_data)
{
    t_node *new_node = (t_node*) malloc(sizeof(t_node));
    t_node *last = *head_ref; 
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
    	*head_ref = new_node;
    	return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}