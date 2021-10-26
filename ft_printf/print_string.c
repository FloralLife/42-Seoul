/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:10:14 by yunolee           #+#    #+#             */
/*   Updated: 2021/10/26 23:10:14 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr("(null)", len);
		return ;
	}
	i = 0;
	while (str[i])
		ft_putchar(str[i++], len);
}
