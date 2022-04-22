/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 04:27:36 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 16:53:29 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_a_2(t_stack *data)
{
	if (data->a->head->is_sort == data->a->tail->is_sort)
	{
		if (data->a->head->sort > data->a->tail->sort)
		{
			data->a->tail->is_sort = TRUE;
			data->sorted += 1;
			sort_a_head_to_tail(data);
		}
		else
		{
			exec_cmd(data, "rra");
			exec_cmd(data, "sa");
			sort_a_head_to_tail(data);
			sort_a_head_to_tail(data);
		}
		return (TRUE);
	}
	else
		exec_cmd(data, "ra");
	return (FALSE);
}

void	sort_a_3(t_stack *data)
{
	while (!is_ordered(data->a))
	{
		if (data->a->head->sort == data->a->head->next->sort + 1)
			exec_cmd(data, "sa");
		else if (data->a->head->sort == data->a->head->next->sort + 2)
			exec_cmd(data, "ra");
		else
			exec_cmd(data, "rra");
	}
}

void	sort_a_5(t_stack *data)
{
	int	i;
	int	sort_cnt;
	int	tmp;

	i = -1;
	sort_cnt = data->a->size - data->sorted;
	tmp = sort_cnt;
	while (++i < tmp - 2)
	{
		if (data->a->head->sort == data->sorted + 1)
		{
			sort_a_head_to_tail(data);
			sort_cnt--;
		}
		else
			exec_cmd(data, "pb");
	}
	sort_ab(data);
	i = -1;
	while (++i < sort_cnt)
	{
		if (data->b->head && data->b->head->sort == data->sorted + 1)
			exec_cmd(data, "pa");
		sort_a_head_to_tail(data);
	}
}

void	sort_ab(t_stack *data)
{
	if (data->b->size == 3)
		sort_b_3(data);
	else if (data->b->size == 2
		&& data->b->head->sort > data->b->head->next->sort)
		exec_cmd(data, "sb");
	if (data->a->head->sort > data->a->head->next->sort
		&& data->a->head->next->is_sort != TRUE)
		exec_cmd(data, "sa");
}

void	sort_a_head_to_tail(t_stack *data)
{
	data->a->head->is_sort = TRUE;
	exec_cmd(data, "ra");
	data->sorted += 1;
}
