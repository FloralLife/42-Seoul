/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:49:49 by yunolee           #+#    #+#             */
/*   Updated: 2021/05/27 00:49:49 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*memchr(const void *ptr, int value, size_t n)
{
	unsigned char	*str;

	str = ptr;
	while (n--)
		if (*str++ == value)
			return (--str);
	return (0);
}
