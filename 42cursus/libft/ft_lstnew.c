/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:32:25 by junseo            #+#    #+#             */
/*   Updated: 2021/11/17 15:37:08 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_ptr;

	list_ptr = malloc(sizeof(t_list));
	if (list_ptr == NULL)
		return (NULL);
	list_ptr -> content = content;
	list_ptr -> next = NULL;
	return (list_ptr);
}
