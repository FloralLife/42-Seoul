/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:17:47 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/02 20:18:23 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_digit(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

void	fill_a(unsigned int num, char *a, int i)
{
	if (num == 0)
		a[i] = '0';
	while (num)
	{
		a[i--] = num % 10 + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	int				sign;
	int				i;
	char			*a;
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		sign = 1;
		num = -n;
	}
	else
		sign = 0;
	i = sign;
	i += count_digit(num);
	a = malloc(i + 1);
	if (a == NULL)
		return (NULL);
	a[i--] = 0;
	fill_a(num, a, i);
	if (sign == 1)
		a[0] = '-';
	return (a);
}
