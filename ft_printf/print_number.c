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
#define HEX "0123456789abcdef"

void	write_nbr(unsigned long num, int *len)
{
	if (num == 0)
		return ;
	write_nbr(num / 10, len);
	ft_putchar(num % 10 + '0', len);
}

void	write_nbr_16(unsigned long num, int *len)
{
	if (num == 0)
		return ;
	write_nbr_16(num / 16, len);
	ft_putchar(HEX[num % 16], len);
}

void	ft_putnbr(int n, int *len, int notation)
{
	unsigned long	num;

	num = n;
	if (n < 0)
	{
		num = -n;
		ft_putchar('-', len);
	}
	else if (n == 0)
		ft_putchar('0', len);
	if (notation == 10)
		write_nbr(num, len);
	else if (notation == 16)
		write_nbr_16(num, len);
}

void	ft_putunbr(unsigned int n, int *len)
{
	unsigned long	num;

	num = n;
	if (n == 0)
		ft_putchar('0', len);
	write_nbr(num, len);
}

void	ft_putptr(void *ptr, int *len)
{
	unsigned long	pointer;

	pointer = (unsigned long)ptr;
	ft_putstr("0x", len);
	if (pointer == 0)
		ft_putchar('0', len);
	write_nbr_16(pointer, len);
}
