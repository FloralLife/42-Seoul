/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:06:26 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/23 22:59:44 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*newlst;
	t_list	*n;
	t_list	*p;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (newlst == NULL)
		return (NULL);
	p = newlst;
	lst = lst->next;
	while (lst)
	{
		n = ft_lstnew(f(lst->content));
		if (n == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		p->next = n;
		lst = lst->next;
		p = n;
	}
	return (newlst);
}
