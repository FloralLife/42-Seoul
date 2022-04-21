/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:53:28 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 02:53:28 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_input(char **input, int size)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		if (is_integer(input[i]))
		{
			arr[i] = ft_atoi(input[i]);
			if (is_unique(arr, i))
				continue ;
		}
		free(arr);
		return (NULL);
	}
	return (arr);
}

int	*input_to_array(char **input, int *size)
{
	int	*arr;

	if (*size == 1)
	{
		input = ft_split(input[0], ' ');
		*size = 0;
		while (input[*size])
			*size += 1;
		arr = parse_input(input, *size);
		free_input(input);
	}
	else
		arr = parse_input(input, *size);
	return (arr);
}

int	find_pos(int *arr, int pos, int size)
{
	int	i;
	int	sort;

	i = -1;
	sort = size;
	while (++i < size)
	{
		if (arr[pos] < arr[i])
			sort--;
	}
	return (sort);
}

void	parse_to_stack(t_stack *data, int size, char **input)
{
	int		*arr;
	int		i;
	int		pos;
	t_node	*tmp;

	arr = input_to_array(input, &size);
	if (!arr)
		error(data);
	i = -1;
	while (++i < size)
	{
		pos = find_pos(arr, i, size);
		tmp = new_node(arr[i], pos);
		if (!tmp)
			error(data);
		listadd_back(data->a, tmp);
	}
	free(arr);
}
