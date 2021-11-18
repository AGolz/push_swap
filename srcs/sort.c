/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 03:42:16 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/24 16:19:30 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/push_swap.h"

void	stack_norm(t_stacks *stks)
{
	int	com;

	set_index(stks->a);
	stks->max_sort = get_max_sort(stks->a);
	stks->len_a = get_count_nod(stks->a);
	if (stks->len_a - stks->max_sort->i - stks->max_sort->sort > 0)
		com = stks->len_a - (stks->len_a
				- stks->max_sort->i - stks->max_sort->sort);
	else
		com = ft_abs(stks->len_a - stks->max_sort->i - stks->max_sort->sort);
	com = nod_itr_up(stks->len_a, com);
	if (com > 0)
		cmd_aap_cnt("ra", com, stks);
	else
		cmd_aap_cnt("rra", com, stks);
}

static void	app_cnt_opt_b(int opt_b, int tmp_b, t_stacks *stks)
{
	if (opt_b > 0)
		cmd_aap_cnt("rb", tmp_b, stks);
	else
		cmd_aap_cnt("rrb", tmp_b, stks);
}

void	nod_b_to_a(t_stacks	*stks)
{
	stks->tmp_b = ft_abs(stks->opt_b);
	stks->tmp_a = ft_abs(stks->opt_a);
	while (((stks->opt_b > 0 && stks->opt_a > 0) || (stks->opt_b < 0
				&& stks->opt_a < 0)) && stks->tmp_b && stks->tmp_a
		&& stks->opt_pl != -1)
	{
		if (stks->opt_b > 0)
			cmd_aap_cnt("rr", 1, stks);
		else
			cmd_aap_cnt("rrr", 1, stks);
		stks->tmp_b--;
		stks->tmp_a--;
	}
	app_cnt_opt_b(stks->opt_b, stks->tmp_b, stks);
	if (stks->opt_pl != -1)
	{
		if (stks->opt_a > 0)
			cmd_aap_cnt("ra", stks->tmp_a, stks);
		else
			cmd_aap_cnt("rra", stks->tmp_a, stks);
	}
	cmd_aap_cnt("pa", 1, stks);
	if (stks->opt_pl == -1)
		cmd_aap_cnt("ra", 1, stks);
}

void	stk_a_to_b(t_stacks	*stks)
{
	t_stack	*stk_a;

	stk_a = stks->a;
	while (stk_a && stk_a->i != stks->max_sort->i)
	{
		stk_a = stk_a->next;
		cmd_aap_cnt("pb", 1, stks);
	}
}

void	stk_b_to_a(t_stacks	*stks)
{
	int		min_cmd;
	int		cmd;
	t_stack	*tmp_b;

	while (stks->b)
	{
		tmp_b = stks->b;
		set_index(stks->a);
		set_index(stks->b);
		stks->len_a = get_count_nod(stks->a);
		stks->len_b = get_count_nod(stks->b);
		min_cmd = stk_set_tmp_cmd(stks, tmp_b);
		stk_copy_tmp_opt_cmd(stks);
		while (tmp_b)
		{
			cmd = stk_set_tmp_cmd(stks, tmp_b);
			if (min_cmd > cmd)
			{
				min_cmd = cmd;
				stk_copy_tmp_opt_cmd(stks);
			}
			tmp_b = tmp_b->next;
		}
		nod_b_to_a(stks);
	}
}
