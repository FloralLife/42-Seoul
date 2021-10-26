/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:57:00 by yunolee           #+#    #+#             */
/*   Updated: 2021/10/26 22:57:00 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_nbr(unsigned int num, int *len)
{
	if (num == 0)
		return ;
	write_nbr(num / 10, len);
	ft_putchar(num % 10 + '0', len);
}

void	write_xnbr(unsigned int num, int *len, int upper)
{
	if (num == 0)
		return ;
	write_xnbr(num / 16, len, upper);
	if (upper)
		ft_putchar(HEX_UPPER[num % 16], len);
	else
		ft_putchar(HEX_LOWER[num % 16], len);
}

void	ft_putnbr(int n, int *len)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		num = -n;
		ft_putchar('-', len);
	}
	else if (n == 0)
		ft_putchar('0', len);
	write_nbr(num, len);
}

void	ft_putxnbr(int n, int *len, int upper)
{
	unsigned int	num;

	num = n;
	if (n == 0)
		ft_putchar('0', len);
	write_xnbr(num, len, upper);
}

void	ft_putunbr(unsigned int n, int *len)
{
	unsigned int	num;

	num = n;
	if (n == 0)
		ft_putchar('0', len);
	write_nbr(num, len);
}
