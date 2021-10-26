/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:48:38 by yunolee           #+#    #+#             */
/*   Updated: 2021/10/27 00:48:38 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_ptr(unsigned long ptr, int *len)
{
	if (ptr == 0)
		return ;
	write_ptr(ptr / 16, len);
	ft_putchar(HEX_LOWER[ptr % 16], len);
}

void	ft_putptr(void *ptr, int *len)
{
	unsigned long	pointer;

	if (ptr == NULL)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	pointer = (unsigned long)ptr;
	ft_putstr("0x", len);
	if (pointer == 0)
		ft_putchar('0', len);
	write_ptr(pointer, len);
}
