/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:16:07 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 03:16:07 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *list)
{
	t_node	*cur;
	t_node	*tmp;

	cur = list->head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(list);
}

void	free_cmdlist(t_cmdlist *list)
{
	t_cmdnode	*cur;
	t_cmdnode	*tmp;

	cur = list->head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(list);
}

void	free_stack(t_stack *data)
{
	if (data)
	{
		if (data->a)
			free_list(data->a);
		if (data->b)
			free_list(data->b);
		if (data->cmdlist)
			free_cmdlist(data->cmdlist);
		free(data);
	}
}

void	free_input(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
