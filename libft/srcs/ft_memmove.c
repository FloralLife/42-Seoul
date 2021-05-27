/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:56:12 by yunolee           #+#    #+#             */
/*   Updated: 2021/05/23 19:25:22 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*memmove(void *dest, const void *src, size_t len)
{
	char	*new_dest;
	char	*new_src;

	if (dest <= src)
	{
		new_dest = (char*)dest;
		new_src = (char*)src;
		while (len--)
			*new_dest++ = *new_src;
	}
	else {
		new_dest = (char*)dest + len - 1;
		new_src = (char*)src + len - 1;
		while (len--)
			*new_dest-- = *new_src;
	}
	return (dest);
}