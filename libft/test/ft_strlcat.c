/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:49:05 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/12 20:25:24 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = 0;
	dest_len = 0;
	i = 0;
	while (src[src_len] != 0)
		src_len++;
	if (size == 0)
		return (src_len);
	while (dest[i] != 0)
		if (i++ < size)
			dest_len++;
	while (i + 1 < size && *src != 0)
		dest[i++] = *src++;
	dest[i] = 0;
	return (dest_len + src_len);
}
