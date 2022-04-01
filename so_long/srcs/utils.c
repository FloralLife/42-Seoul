/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:35:49 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/01 15:14:03 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_substr(char *str, int start, int end)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(str);
	if (len < end)
		end = len;
	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < end)
	{
		if (i >= start)
			ret[i - start] = str[i];
		i++;
	}
	ret[i - start] = 0;
	return (ret);
}

char	*ft_strjoin(char *a, char *b)
{
	int		i;
	int		alen;
	int		blen;
	char	*ret;

	alen = ft_strlen(a);
	blen = ft_strlen(b);
	ret = (char *)malloc(sizeof(char) * (alen + blen + 1));
	if (ret != NULL)
	{
		i = 0;
		while (i < alen + blen)
		{
			if (i < alen)
				ret[i] = a[i];
			else
				ret[i] = b[i - alen];
			i++;
		}
		ret[i] = 0;
	}
	return (ret);
}

void	freeMap(t_mapInfo mapInfo)
{
	int	i;

	i = mapInfo.size.height;
	while (i--)
		free(mapInfo.map[i]);
	free(mapInfo.map);
}
