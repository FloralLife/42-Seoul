/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 05:06:07 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/22 05:06:07 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*b1;
	unsigned char	*b2;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 != s2)
			return (-1);
		return (0);
	}
	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	while (*b1 || *b2)
	{
		if (*b1 != *b2)
			return (*b1 - *b2);
		if (*b1 == '\0')
			return (0);
		b1++;
		b2++;
	}
	return (0);
}
