/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:08:21 by yunolee           #+#    #+#             */
/*   Updated: 2021/05/30 16:08:21 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = ft_strlen(str);
	dup = (char*)malloc(len * sizeof(char));
	if (dup == NULL)
		return (dup);
	i = -1;
	while (++i < len)
		dup[i] = str[i];
	return (dup);
}
