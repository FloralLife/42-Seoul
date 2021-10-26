/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:51:28 by yunolee           #+#    #+#             */
/*   Updated: 2021/10/24 14:51:28 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type(const char *format, int *i, va_list args, int *len)
{
	char	type;

	(*i)++;
	type = format[*i];
	if (type == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (type == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (type == 'p')
		ft_putptr(va_arg(args, void *), len);
	else if (type == 'd' || type == 'i')
		ft_putnbr(va_arg(args, int), len, 10);
	else if (type == 'u')
		ft_putunbr(va_arg(args, unsigned int), len);
	else if (type == 'x')
		ft_putnbr(va_arg(args, int), len, 16);
	else if (type == '%')
		ft_putchar('%', len);
}

int	parse_format(const char *format, va_list args)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
			print_type(format, &i, args, &ret);
		else
			ft_putchar(format[i], &ret);
		i++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;

	va_start(args, format);
	ret = parse_format(format, args);
	va_end(args);
	return (ret);
}
