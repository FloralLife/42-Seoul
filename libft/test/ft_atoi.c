/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:04:06 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/12 19:51:12 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

int		check_overflow(unsigned long long num, int sign)
{
	if (num > (unsigned long long)LLONG_MAX + 1 && sign == -1)
		return (0);
	if (num > LLONG_MAX && sign == 1)
		return (-1);
	return (num * sign);
}

int		ft_atoi(const char *str)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while (*str)
	{
		if ((*str < 9 || *str > 13) && *str != ' ')
			break ;
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9'
		&& num <= (unsigned long long)LLONG_MAX + 1)
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (check_overflow(num, sign));
}
