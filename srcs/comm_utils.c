/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 04:48:35 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/23 17:40:32 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/push_swap.h"

int	cmd_app_s(t_stack **stk)
{
	int	tmp;

	if (*stk && (*stk)->next)
	{
		tmp = (*stk)->val;
		(*stk)->val = (*stk)->next->val;
		(*stk)->next->val = tmp;
		return (1);
	}
	return (-1);
}

int	cmd_app_r(t_stack **stk)
{
	if (*stk && (*stk)->next)
	{
		push_back(stk, pp_front(stk));
		return (1);
	}
	return (-1);
}

int	cmd_app_rr(t_stack **stk)
{
	if (*stk && (*stk)->next)
	{
		push_front(stk, pp_back(stk));
		return (1);
	}
	return (-1);
}

int	cmd_app_p(t_stack **st_dst, t_stack **st_src)
{
	if (*st_dst)
	{
		push_front(st_src, pp_front(st_dst));
		return (1);
	}
	return (-1);
}
