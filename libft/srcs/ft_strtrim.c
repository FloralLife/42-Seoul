/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:54:38 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/05 19:01:14 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		isset(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;
	int		len;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && isset(s1[start], set))
		start++;
	while (start <= end && isset(s1[end], set))
		end--;
	len = end - start + 1;
	str = malloc(len + 1);
	if (str == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i++] = s1[start++];
	}
	str[len] = 0;
	return (str);
}
