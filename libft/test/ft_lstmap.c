/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:06:26 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/03 18:06:26 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*lstmap;
	t_list	*n;
	t_list	*p;
	t_list	*next_node;

	p = NULL;
	while (lst)
	{
		n = (t_list*)malloc(sizeof(t_list));
		n->content = f(lst->content);
		if (p)
			p->next = n;
		else
			lstmap = n;
		next_node = lst->next;
		ft_lstdelone(lst, del);
		lst = next_node;
	}
	n->next = NULL;
	return (lstmap);
}
