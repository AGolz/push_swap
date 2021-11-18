/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:00:49 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/24 04:30:47 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/push_swap.h"

t_stack	*pp_front(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return (NULL);
	tmp = *stack;
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
		*stack = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

t_stack	*pp_back(t_stack **stack)
{
	t_stack	*lst;
	t_stack	*tmp;

	lst = *stack;
	tmp = *stack;
	if (*stack == NULL)
		return (NULL);
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		while (lst->next && lst->next->next)
			lst = lst->next;
		tmp = lst->next;
		lst->next = NULL;
	}
	return (tmp);
}

void	stk_a_min_top(t_stacks *stks)
{
	t_stack	*tmp_a;
	t_stack	*min_nod;
	int		itr_up;

	tmp_a = stks->a;
	min_nod = tmp_a;
	while (tmp_a)
	{
		if (tmp_a->val < min_nod->val)
			min_nod = tmp_a;
		tmp_a = tmp_a->next;
	}
	stks->len_a = get_count_nod(stks->a);
	set_index(stks->a);
	itr_up = nod_itr_up(stks->len_a, min_nod->i);
	if (itr_up > 0)
		cmd_aap_cnt("ra", itr_up, stks);
	else
		cmd_aap_cnt("rra", itr_up, stks);
}
