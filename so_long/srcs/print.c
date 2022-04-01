/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 03:01:16 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/01 15:13:46 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++), 1);
}

void	ft_putError(char *errMsg)
{
	while (*errMsg)
		ft_putchar(*(errMsg++), 2);
}

void	write_nbr(unsigned int num)
{
	if (num == 0)
		return ;
	write_nbr(num / 10);
	ft_putchar(num % 10 + '0', 1);
}

void	ft_putnbr(int n)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		num = -n;
		ft_putchar('-', 1);
	}
	else if (n == 0)
		ft_putchar('0', 1);
	write_nbr(num);
}
