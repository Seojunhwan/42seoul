/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:52:29 by junseo            #+#    #+#             */
/*   Updated: 2022/06/25 21:51:30 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include "stdlib.h"

typedef struct s_list
{
	int				data;
	struct t_list	*prev;
	struct t_list	*next;
}				t_list;

typedef struct s_stack
{
	int			size;
	t_list		*a;
}				t_stack;

typedef struct s_info
{
	t_stack		a;
	t_stack		b;
}				t_info;

#endif