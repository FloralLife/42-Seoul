/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 04:19:05 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 04:19:05 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_list *list)
{
	t_node	*node;

	node = list->head;
	while (node->next)
	{
		if (node->sort > node->next->sort)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

int	is_ordered_reverse(t_list *list)
{
	t_node	*node;

	node = list->head;
	while (node->next)
	{
		if (node->sort < node->next->sort)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}
