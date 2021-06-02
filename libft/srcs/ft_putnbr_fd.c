/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:56:54 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/02 23:57:51 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_nbr(unsigned int num, int fd)
{
	if (num == 0)
		return ;
	write_nbr(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int num;

	num = n;
	if (n < 0)
	{
		num = -n;
		ft_putchar_fd('-', fd);
	}
	write_nbr(num, fd);
}

#include <limits.h>
int main()
{
	ft_putnbr_fd(INT_MIN, 1);
}
