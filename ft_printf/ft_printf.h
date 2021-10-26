/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:45:59 by yunolee           #+#    #+#             */
/*   Updated: 2021/10/24 14:45:59 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

#define HEX_UPPER "0123456789ABCDEF"
#define HEX_LOWER "0123456789abcdef"

# include <stdio.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putxnbr(int n, int *len, int upper);
void	ft_putunbr(unsigned int n, int *len);
void	ft_putptr(void *ptr, int *len);

#endif
