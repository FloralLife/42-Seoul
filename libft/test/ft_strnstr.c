/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:09:34 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/05 19:01:51 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t i;
	size_t j;
	size_t str_len;
	size_t find_len;

	i = 0;
	str_len = ft_strlen(str);
	find_len = ft_strlen(find);
	if (find_len == 0)
		return ((char*)str);
	while (i + find_len <= str_len && i + find_len <= n)
	{
		if (str[i] == find[0])
		{
			j = 1;
			while (str[i + j] == find[j])
			{
				if (find[++j] == 0)
					return ((char*)str + i);
			}
		}
		i++;
	}
	return (0);
}
