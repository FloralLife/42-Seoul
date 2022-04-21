/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 04:27:45 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 04:27:45 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_b_2(t_stack *data)
{
	exec_cmd(data, "pa");
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

void	sort_b_3_desc(t_stack *data)
{
	while (!is_ordered_reverse(data->b))
	{
		if (data->b->head->sort == data->b->head->next->sort - 1)
			exec_cmd(data, "sb");
		else if (data->b->head->sort == data->b->head->next->sort - 2)
			exec_cmd(data, "rb");
		else
			exec_cmd(data, "rrb");
	}
}

void	sort_b_3(t_stack *data)
{
	while (!is_ordered(data->b))
	{
		if (data->b->head->sort > data->b->head->next->sort
			&& data->b->head->sort > data->b->tail->sort)
			exec_cmd(data, "rb");
		else if (data->b->tail->sort < data->b->head->next->sort
			&& data->b->tail->sort < data->b->head->sort)
			exec_cmd(data, "rrb");
		else
			exec_cmd(data, "sb");
	}
}

void	sort_b_small3(t_stack *data)
{
	int	i;

	exec_cmd(data, "rrb");
	exec_cmd(data, "pa");
	exec_cmd(data, "rrb");
	exec_cmd(data, "rrb");
	if (data->b->head->sort > data->b->head->next->sort)
		exec_cmd(data, "sb");
	i = -1;
	while (++i < 3)
	{
		if (data->b->head && data->b->head->sort == data->sorted + 1)
			exec_cmd(data, "pa");
		sort_a_head_to_tail(data);
	}
}

void	sort_b_5(t_stack *data)
{
	int	idx;
	int	sort_cnt;

	sort_cnt = data->b->size;
	while (data->b->size > 3)
	{
		exec_cmd(data, "pa");
		if (data->a->head->sort == data->sorted + 1)
		{
			sort_a_head_to_tail(data);
			sort_cnt--;
		}
	}
	sort_b_3(data);
	if (data->a->head->sort > data->a->head->next->sort
		&& data->a->head->next->is_sort == FALSE)
		exec_cmd(data, "sa");
	idx = -1;
	while (++idx < sort_cnt)
	{
		if (data->b->head && data->b->head->sort == data->sorted + 1)
		{
			exec_cmd(data, "pa");
		}
		sort_a_head_to_tail(data);
	}
}
