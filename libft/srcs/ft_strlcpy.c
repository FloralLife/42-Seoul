/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 01:05:53 by yunolee           #+#    #+#             */
/*   Updated: 2021/05/27 01:05:53 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t len;

	len = 0;
	while (src[len] && len + 1 < n)
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = 0;
	return (ft_strlen(src));
}
