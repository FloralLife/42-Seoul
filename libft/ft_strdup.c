/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:08:21 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/05 17:16:15 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = ft_strlen(str);
	dup = (char*)malloc(len + 1);
	if (dup == NULL)
		return (dup);
	i = -1;
	while (++i < len)
		dup[i] = str[i];
	dup[i] = 0;
	return (dup);
}
