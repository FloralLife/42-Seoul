/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 03:01:16 by yunolee           #+#    #+#             */
/*   Updated: 2022/03/30 03:07:28 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (str)
		ft_putchar(*(str++));
}

void	write_nbr(unsigned int num)
{
	if (num == 0)
		return ;
	write_nbr(num / 10);
	ft_putchar(num % 10 + '0');
}

void	ft_putnbr(int n, int *len)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		num = -n;
		ft_putchar('-');
	}
	else if (n == 0)
		ft_putchar('0');
	write_nbr(num);
}
