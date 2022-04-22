/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 04:21:58 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 17:24:56 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_btoa(t_stack *data)
{
	int	flag;
	int	sort_cnt;
	int	pivot;
	int	i;

	flag = FALSE;
	sort_cnt = data->b->size;
	pivot = data->sorted + data->b->size / 2;
	i = -1;
	while (++i < sort_cnt)
	{
		if (!flag && data->b->head->sort <= data->sorted + 2)
			flag = sort_b_2(data);
		else if (flag && data->b->head->sort == data->sorted + 1)
		{
			exec_cmd(data, "pa");
			sort_a_head_to_tail(data);
		}
		else if (data->b->head->sort > pivot)
			exec_cmd(data, "pa");
		else
			exec_cmd(data, "rb");
	}
}

void	sort_atob(t_stack *data)
{
	int	flag;
	int	is_sort;

	flag = FALSE;
	is_sort = data->a->head->is_sort;
	while (data->a->head && is_sort == data->a->head->is_sort)
	{
		if (!flag && data->a->head->sort <= data->sorted + 2)
			flag = sort_a_2(data);
		else if (flag && data->a->head->sort == data->sorted + 1)
			sort_a_head_to_tail(data);
		else
			exec_cmd(data, "pb");
	}
}

void	seperate_ab(t_stack *data)
{
	int	i;
	int	pivot;

	i = -1;
	pivot = data->list_size / 2 + 1;
	while (++i < data->list_size)
	{
		if (data->a->head->sort < pivot)
		{
			exec_cmd(data, "pb");
			if (data->b->head->sort <= data->sorted + 3)
				exec_cmd(data, "rb");
		}
		else
		{
			exec_cmd(data, "ra");
		}
	}
	sort_b_small3(data);
}

void	sort_6(t_stack *data)
{
	if (data->a->size <= 3)
		sort_a_3(data);
	else
	{
		while (data->a->size > 3)
		{
			if (data->a->head->sort <= data->list_size - 3)
				exec_cmd(data, "pb");
			else
				exec_cmd(data, "ra");
		}
		sort_a_3(data);
		sort_b_3_desc(data);
		while (data->b->size)
			exec_cmd(data, "pa");
	}
	data->sorted = data->list_size;
}

void	sort(t_stack *data)
{
	if (data->list_size <= 6)
		sort_6(data);
	else
	{
		seperate_ab(data);
		while (!is_ordered(data->a) || !(data->list_size == data->sorted))
		{
			if (data->b->size > 0 && data->b->size <= 5)
				sort_b_5(data);
			else if (data->b->size > 5)
				sort_btoa(data);
			else if (data->a->size - data->sorted > 0
				&& data->a->size - data->sorted <= 5)
				sort_a_5(data);
			else if (data->a->size - data->sorted > 5)
				sort_atob(data);
		}
	}
}
