/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 04:47:34 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 04:47:34 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_stack(t_list *list)
{
	t_node	*tmp;

	if (!list->head || !list->head->next)
		return (FALSE);
	tmp = list->head->next;
	if (tmp->next)
		tmp->next->prev = list->head;
	list->head->prev = tmp;
	list->head->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = list->head;
	list->head = tmp;
	return (TRUE);
}

int	rrotate_stack(t_list *list)
{
	t_node	*tmp;

	if (!list->head || !list->head->next)
		return (FALSE);
	tmp = list->tail;
	list->tail = list->tail->prev;
	list->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = list->head;
	list->head->prev = tmp;
	list->head = tmp;
	return (TRUE);
}

int	rotate_stack(t_list *list)
{
	t_node	*tmp;

	if (!list->head || !list->head->next)
		return (FALSE);
	tmp = list->head;
	list->head = list->head->next;
	list->head->prev = NULL;
	tmp->prev = list->tail;
	tmp->next = NULL;
	list->tail->next = tmp;
	list->tail = tmp;
	return (TRUE);
}

int	push_stack(t_list *list_to, t_list *list_from)
{
	t_node	*tmp;

	if (!list_from->head)
		return (FALSE);
	tmp = list_from->head;
	if (!list_from->head->next)
	{
		list_from->head = NULL;
		list_from->tail = NULL;
	}
	else
	{
		list_from->head = list_from->head->next;
		list_from->head->prev = NULL;
	}
	list_from->size--;
	tmp->next = NULL;
	listadd_front(list_to, tmp);
	return (TRUE);
}
