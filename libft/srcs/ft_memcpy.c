/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:55:06 by yunolee           #+#    #+#             */
/*   Updated: 2021/05/23 17:50:34 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char	*n_dest;
	char	*n_src;

	n_dest = (char*)dest;
	n_src = (char*)src;
	while (len--)
		*n_dest++ = *n_src++;
	return (dest);
}
