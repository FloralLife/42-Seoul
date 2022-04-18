/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:34:34 by yunolee           #+#    #+#             */
/*   Updated: 2022/02/23 01:34:34 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_nbr(unsigned int num)
{
	if (num == 0)
		return ;
	write_nbr(num / 10);
	ft_putchar(num % 10 + '0');
}

void	ft_putnbr(int n)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		num = -n;
		ft_putchar('-');
	}
	else if (n == 0)
	{
		ft_putchar('0');
	}
	write_nbr(num);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}
