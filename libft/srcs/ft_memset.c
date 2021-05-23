/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:09:47 by yunolee           #+#    #+#             */
/*   Updated: 2021/05/23 15:21:53 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memset(void *ptr, int value, unsigned int len)
{
	char *str;

	str = ptr;
	while (len--)
	{
		*str++ = value;
	}
	return ptr;
}
