/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:04:45 by junseo            #+#    #+#             */
/*   Updated: 2021/11/20 20:01:03 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	size_t	i;
	t_list	**lists;

	lists = (t_list **)malloc(sizeof(t_list *) * ft_lstsize(lst) + 1);
	i = 0;
	while (lst)
	{
		lists[i] = ft_lstnew(f(lst->content));
		if (lists[i] == NULL)
		{
			ft_lstclear(lists, del);
			return (NULL);
		}
		lst = lst->next;
		if (i > 0)
			lists[i - 1]->next = lists[i];
		i++;
	}
	lists[i] = NULL;
	return (*lists);
}
