/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:56:19 by yunolee           #+#    #+#             */
/*   Updated: 2021/05/27 00:56:19 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	memcmp(const void *ptr1, const void *ptr2, sizt_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = ptr1;
	b = ptr2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}
