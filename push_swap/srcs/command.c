/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 04:31:50 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 17:18:20 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmdnode	*cmd_combine(t_stack *data, char *cmd, char *prevcmd)
{
	t_cmdnode	*ret;
	int			combine;

	combine = TRUE;
	if ((!ft_strcmp(cmd, "sa") && !ft_strcmp(prevcmd, "sb"))
		|| (!ft_strcmp(cmd, "sb") && !ft_strcmp(prevcmd, "sa")))
		ret = new_cmdnode("ss");
	else if ((!ft_strcmp(cmd, "ra") && !ft_strcmp(prevcmd, "rb"))
		|| (!ft_strcmp(cmd, "rb") && !ft_strcmp(prevcmd, "ra")))
		ret = new_cmdnode("rr");
	else if ((!ft_strcmp(cmd, "rra") && !ft_strcmp(prevcmd, "rrb"))
		|| (!ft_strcmp(cmd, "rrb") && !ft_strcmp(prevcmd, "rra")))
		ret = new_cmdnode("rrr");
	else
	{
		ret = new_cmdnode(cmd);
		combine = FALSE;
	}
	if (!ret)
		error(data);
	if (combine)
		cmdlistdlt_back(data->cmdlist);
	return (ret);
}

void	add_cmd(t_stack *data, char *cmd)
{
	t_cmdnode	*tmp;
	char		*prevcmd;

	prevcmd = NULL;
	tmp = NULL;
	if (data->cmdlist->tail)
		prevcmd = data->cmdlist->tail->cmd;
	if (!ft_strcmp(cmd, "pa"))
		data->a->head->is_sort += 1;
	else if (!ft_strcmp(cmd, "pb"))
		data->b->head->is_sort += 1;
	else if (!ft_strcmp(cmd, "rb"))
		data->b->tail->is_sort += 1;
	if ((!ft_strcmp(cmd, "ra") && !ft_strcmp(prevcmd, "rra"))
		|| (!ft_strcmp(cmd, "rra") && !ft_strcmp(prevcmd, "ra"))
		|| (!ft_strcmp(cmd, "rb") && !ft_strcmp(prevcmd, "rrb"))
		|| (!ft_strcmp(cmd, "rrb") && !ft_strcmp(prevcmd, "rb")))
		cmdlistdlt_back(data->cmdlist);
	else
	{
		tmp = cmd_combine(data, cmd, prevcmd);
		cmdlistadd_back(data->cmdlist, tmp);
	}
}

void	exec_cmd(t_stack *data, char *cmd)
{
	int	res;

	res = FALSE;
	if (!ft_strcmp(cmd, "sa"))
		res = swap_stack(data->a);
	else if (!ft_strcmp(cmd, "sb"))
		res = swap_stack(data->b);
	else if (!ft_strcmp(cmd, "ra"))
		res = rotate_stack(data->a);
	else if (!ft_strcmp(cmd, "rb"))
		res = rotate_stack(data->b);
	else if (!ft_strcmp(cmd, "rra"))
		res = rrotate_stack(data->a);
	else if (!ft_strcmp(cmd, "rrb"))
		res = rrotate_stack(data->b);
	else if (!ft_strcmp(cmd, "pa"))
		res = push_stack(data->a, data->b);
	else if (!ft_strcmp(cmd, "pb"))
		res = push_stack(data->b, data->a);
	if (res == TRUE)
		add_cmd(data, cmd);
}
