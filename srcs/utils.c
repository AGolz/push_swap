/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 04:15:29 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/23 19:44:08 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/push_swap.h"

static void	free_stk(t_stack **stk)
{
	t_stack	*next;

	while (*stk)
	{
		next = (*stk)->next;
		free(*stk);
		*stk = next;
	}
}

int	free_stks(t_stacks **stks, int ret_num)
{
	if (*stks && (*stks)->a)
		free_stk(&(*stks)->a);
	if (*stks && (*stks)->b)
		free_stk(&(*stks)->b);
	if (*stks)
		free(*stks);
	return (ret_num);
}

int	stk_set_tmp_cmd(t_stacks *stks, t_stack *tmp_b)
{
	stks->tmp_pl = get_nod_place_i(stks->a, tmp_b->val);
	stks->tmp_b = nod_itr_up(stks->len_b, tmp_b->i);
	stks->tmp_a = nod_itr_up(stks->len_a, stks->tmp_pl);
	return (nod_b_to_a_count(stks->tmp_a, stks->tmp_b, stks->tmp_pl));
}

void	stk_copy_tmp_opt_cmd(t_stacks *stks)
{
	stks->opt_pl = stks->tmp_pl;
	stks->opt_b = stks->tmp_b;
	stks->opt_a = stks->tmp_a;
}

void	put_error(t_stacks **stk, int ret_num)
{
	ft_putstr("Error\n");
	free_stks(stk, ret_num);
	exit(ret_num);
}
