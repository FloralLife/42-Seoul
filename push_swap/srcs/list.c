/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:41:17 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 17:18:50 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value, int sort)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->value = value;
	node->sort = sort;
	node->is_sort = FALSE;
	return (node);
}

void	listadd_back(t_list *list, t_node *new)
{
	if (list->size == 0)
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
	list->size++;
}

void	listadd_front(t_list *list, t_node *new)
{
	if (!list->size)
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
	list->size++;
}
