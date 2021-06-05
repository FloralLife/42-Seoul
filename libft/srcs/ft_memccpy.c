/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:29:48 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/05 16:02:32 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*n_dest;
	unsigned char	*n_src;

	n_dest = (unsigned char*)dest;
	n_src = (unsigned char*)src;
	while (n--)
	{
		if (*n_src == c)
		{
			*n_dest++ = *n_src;
			return (n_dest);
		}
		*n_dest++ = *n_src++;
	}
	return (NULL);
}
