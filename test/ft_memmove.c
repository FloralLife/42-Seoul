/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:56:12 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/05 17:22:24 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;

	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		new_dest = (unsigned char*)dest;
		new_src = (unsigned char*)src;
		while (len--)
			*new_dest++ = *new_src++;
	}
	else
	{
		new_dest = (unsigned char*)dest + len - 1;
		new_src = (unsigned char*)src + len - 1;
		while (len--)
			*new_dest-- = *new_src--;
	}
	return (dest);
}
