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

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*n_dest;
	unsigned char	*n_src;

	if (!dest && !src)
		return (0);
	n_dest = (unsigned char*)dest;
	n_src = (unsigned char*)src;
	while (len--)
		*n_dest++ = *n_src++;
	return (dest);
}

#include <stdio.h>
int main(){
	char *dest = NULL;
	char *src = NULL;
	printf("%s", (char*)memcpy(dest, src, 6));
}
