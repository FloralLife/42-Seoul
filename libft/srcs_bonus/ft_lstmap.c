/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:06:26 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/12 19:52:37 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*lstmap;
	t_list	*n;
	t_list	*p;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		if ((n = ft_lstnew(f(lst->content))) == NULL)
		{
			if (lstmap)
				ft_lstclear(&lstmap, del);
			return (NULL);
		}
		if (lstmap)
			p->next = n;
		else
			lstmap = n;
		lst = lst->next;
		p = n;
	}
	return (lstmap);
}
