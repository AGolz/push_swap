/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 03:30:28 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/23 18:35:59 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/push_swap.h"

void	push_back(t_stack **stk, t_stack *new)
{
	t_stack	*last;

	if (*stk == NULL)
	{
		*stk = new;
		return ;
	}
	last = get_last_nod(*stk);
	last->next = new;
}

void	push_front(t_stack **stk, t_stack *new)
{
	if (*stk == NULL)
		*stk = new;
	else
	{
		new->next = *stk;
		*stk = new;
	}
}

t_stack	*push_back_int(t_stack **stk, int val)
{
	t_stack	*new;

	new = create_new_nod(val);
	if (new == NULL)
		return (NULL);
	push_back(stk, new);
	return (*stk);
}
