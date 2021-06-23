/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:33:08 by yunolee           #+#    #+#             */
/*   Updated: 2021/05/29 18:33:08 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void *ret;

	ret = malloc(nelem * elsize);
	if (ret == NULL)
		return (0);
	ft_memset(ret, 0, nelem * elsize);
	return (ret);
}
