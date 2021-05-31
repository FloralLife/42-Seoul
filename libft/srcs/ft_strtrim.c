/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:54:38 by yunolee           #+#    #+#             */
/*   Updated: 2021/05/31 19:54:38 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		isSet(char c, char const *set)
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
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s1[i])
	{
		if(isSet(s1[i++]))
			len++;
	}
	str = malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (0);
	i = 0;
	len = 0;
	while (s1[i])
	{
		if (isSet(s1[i]))
			str[len++] = s1[i];
		i++;
	}
	return (str);
}
