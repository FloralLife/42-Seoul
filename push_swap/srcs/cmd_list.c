/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 04:49:55 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 04:49:55 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmdnode	*new_cmdnode(char *cmd)
{
	t_cmdnode	*node;

	node = (t_cmdnode *)malloc(sizeof(t_cmdnode));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->cmd = cmd;
	return (node);
}

void	cmdlistadd_back(t_cmdlist *list, t_cmdnode *new)
{
	if (!list->head)
	{
		list->head = new;
		list->tail = new;
	}
	else
	{
		new->prev = list->tail;
		list->tail->next = new;
		list->tail = new;
	}
}

void	cmdlistadd_front(t_cmdlist *list, t_cmdnode *new)
{
	if (!list->head)
	{
		list->head = new;
		list->tail = new;
	}
	else
	{
		new->next = list->head;
		list->head->prev = new;
		list->head = new;
	}
}

void	cmdlistdlt_back(t_cmdlist *list)
{
	t_cmdnode	*tmp;

	if (list->tail)
	{
		if (list->head == list->tail)
		{
			free(list->head->cmd);
			free(list->head);
			list->head = NULL;
			list->tail = NULL;
		}
		else
		{
			tmp = list->tail->prev;
			free(list->tail);
			list->tail = tmp;
		}
	}
}
