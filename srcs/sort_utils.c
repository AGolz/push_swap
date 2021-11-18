/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:51:03 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/24 12:24:26 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/push_swap.h"

static void	get_max_small(t_stack *stk, t_stack *tmp, t_stack *first)
{
	if (tmp->next == NULL)
	{
		if (first->val < tmp->val)
			return ;
	}
	else
		if (tmp->next->val < tmp->val)
			return ;
	stk->sort++;
	if (tmp->next == NULL)
		tmp = first;
	else
		tmp = tmp->next;
	return ;
}

t_stack	*get_max_sort(t_stack *stk)
{
	int		nodes;
	int		i;
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*max;

	first = stk;
	max = stk;
	nodes = get_count_nod(stk);
	while (stk)
	{
		tmp = stk;
		i = 0;
		while (i < nodes)
		{
			get_max_small(stk, tmp, first);
			i++;
		}
		if (stk->sort >= max->sort)
			max = stk;
		stk = stk->next;
	}
	return (max);
}

int	nod_itr_up(int stk_len, int nod_i)
{
	if (stk_len / 2 >= nod_i)
	{
		return (nod_i);
	}
	else
	{	
		return ((stk_len - nod_i) * -1);
	}
}

int	get_nod_place_i(t_stack *stk, int nod_val)
{
	t_stack	*optm;
	int		last_min;

	optm = NULL;
	last_min = 0;
	while (stk)
	{
		if ((last_min == 0) || (last_min < 0 && stk->val - nod_val < 0
				&& stk->val - nod_val > last_min) || (last_min > 0
				&& stk->val - nod_val < last_min))
		{
			last_min = stk->val - nod_val;
			optm = stk;
		}
		if (stk->next == NULL)
			break ;
		stk = stk->next;
	}
	if (optm == stk && last_min < 0)
		return (-1);
	if (last_min < 0)
		return (optm->i + 1);
	else
		return (optm->i);
}
