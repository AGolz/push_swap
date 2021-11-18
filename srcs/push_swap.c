/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 10:53:03 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/24 17:11:49 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/push_swap.h"

static void	sort_two(t_stacks *stks)
{
	if (stks->a->val > stks->a->next->val)
		cmd_aap_cnt("sa", 1, stks);
}

static void	sort_three(t_stacks *stks)
{
	while (!sort_stacks_check(stks))
	{
		if ((stks->a->val < stks->a->next->val && stks->a->val
				> stks->a->next->next->val) && (stks->a->next->val
				> stks->a->val && stks->a->next->val
				> stks->a->next->next->val))
			cmd_aap_cnt("rra", 1, stks);
		else if ((stks->a->val > stks->a->next->val && stks->a->val
				> stks->a->next->next->val) && (stks->a->next->val
				< stks->a->val && stks->a->next->val
				< stks->a->next->next->val))
			cmd_aap_cnt("ra", 1, stks);
		else
			cmd_aap_cnt("sa", 1, stks);
	}
}

static void	sort_five(t_stacks *stks)
{
	if (stks->max_sort->sort > 3)
	{
		cmd_aap_cnt("pb", 2, stks);
		sort_three(stks);
	}
	else
		stk_a_to_b(stks);
	stk_b_to_a(stks);
	stk_a_min_top(stks);
}

static void	sort_other(t_stacks *stks)
{
	stk_a_to_b(stks);
	stk_b_to_a(stks);
	stk_a_min_top(stks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stks;

	stks = create_stacks(argc, argv);
	if (stks->a == NULL)
		exit(free_stks(&stks, 0));
	if (sort_stacks(stks) == 1)
		exit(free_stks(&stks, 0));
	stks->cmd_print = 1;
	stks->len_a = get_count_nod(stks->a);
	stack_norm(stks);
	if (stks->len_a == 2)
		sort_two(stks);
	if (stks->len_a == 3)
		sort_three(stks);
	else if (stks->len_a <= 5)
		sort_five(stks);
	else
		sort_other(stks);
	return (free_stks(&stks, 0));
}
