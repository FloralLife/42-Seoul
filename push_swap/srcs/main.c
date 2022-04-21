/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:28:37 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/21 23:28:37 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*data;

	data = (t_stack *)malloc(sizeof(t_stack));
	if (!data)
		error(data);
	data->a = (t_list *)malloc(sizeof(t_list));
	data->b = (t_list *)malloc(sizeof(t_list));
	data->cmdlist = (t_cmdlist *)malloc(sizeof(t_cmdlist));
	if (!data->a || !data->b)
		error(data);
	data->a->head = NULL;
	data->a->tail = NULL;
	data->a->size = 0;
	data->b->head = NULL;
	data->b->tail = NULL;
	data->b->size = 0;
	data->cmdlist->head = NULL;
	data->cmdlist->tail = NULL;
	data->sorted = 0;
	data->list_size = 0;
	return (data);
}

int	main(int argc, char **argv)
{
	t_stack		*data;
	t_cmdnode	*tmp;

	if (argc > 1)
	{
		data = init_stack();
		parse_to_stack(data, argc - 1, ++argv);
		data->list_size = data->a->size;
		if (!is_ordered(data->a))
			sort(data);
		tmp = data->cmdlist->head;
		// printf("final : ");
		// print(data->a);
		// print(data->b);
		// printf("%d\n", data->sorted);
		while (tmp)
		{
			ft_putstr(tmp->cmd);
			ft_putstr("\n");
			tmp = tmp->next;
		}
		free_stack(data);
	}
}
