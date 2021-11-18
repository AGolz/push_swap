/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:21:03 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/24 17:12:15 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/push_swap.h"

void	set_index(t_stack *stk)
{
	int	i;

	i = 0;
	while (stk)
	{
		stk->i = i;
		i++;
		stk = stk->next;
	}
}

int	nod_b_to_a_count(int a, int b, int plc_b)
{
	if (a > 0 && b > 0 && plc_b != -1)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	if (a < 0 && b < 0 && plc_b != -1)
	{
		if (ft_abs(a) > ft_abs(b))
			return (ft_abs(a));
		else
			return (ft_abs(b));
	}
	else
		return (ft_abs(a) + ft_abs(b));
}
