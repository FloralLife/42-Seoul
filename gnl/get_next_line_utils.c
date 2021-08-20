/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:35:49 by yunolee           #+#    #+#             */
/*   Updated: 2021/08/19 16:35:49 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return len;
}

char	*ft_substr(char *str, int start, int end)
{
	char	*origin;
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(str);
	if (len < end)
		end = len;
	ret = (char*)malloc(sizeof(char) * (len - end + start + 1));
	if (ret == NULL)
		return null;
	i = 0;
	while (i < len && i < end){
		if (i >= start)
			ret[i] = *str[i];
		i++;
	}
	ret[i] = 0;
	return ret;
}

char	*ft_strjoin(char *a, char *b)
{
	int		i;
	int		alen;
	int		blen;
	char	*ret;

	alen = ft_strlen(a);
	blen = ft_strlen(b);
	ret = (char*)malloc(sizeof(char) * (alen + blen + 1));
	i = -1;
	while (++i < alen)
		ret[i] = a[i];
	while (++i < alen + blen)
		ret[i] = b[i - alen];
	ret[i] = 0;
	free(a);
	free(b);
	return ret;
}
