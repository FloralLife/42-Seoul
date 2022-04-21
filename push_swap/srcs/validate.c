/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:35:44 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 03:35:44 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(char *str)
{
	int		sign;
	long	nbr;
	int		flag;

	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	nbr = 0;
	flag = 0;
	while (*str >= '0' && *str <= '9' && nbr - 1 <= INT_MAX)
	{
		nbr = nbr * 10 + *str - '0';
		str++;
		flag = 1;
	}
	nbr = nbr * sign;
	if (*str != 0 || flag == 0 || nbr < INT_MIN || nbr > INT_MAX)
		return (FALSE);
	return (TRUE);
}

int	is_unique(int *arr, int idx)
{
	int	i;

	i = -1;
	while (++i < idx)
	{
		if (arr[i] == arr[idx])
			return (FALSE);
	}
	return (TRUE);
}
