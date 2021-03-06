/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:37:41 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/23 19:52:31 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ret;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	ret = str;
	i = 0;
	while (s1[i])
		*str++ = s1[i++];
	i = 0;
	while (s2[i])
		*str++ = s2[i++];
	*str = 0;
	return (ret);
}
