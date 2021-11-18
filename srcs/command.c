/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 04:17:05 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/24 08:08:25 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/push_swap.h"

static void	cmd_print(char *com)
{
	ft_putstr(com);
	ft_putchar('\n');
}

static int	cmd_len(int len, int res, char *com, t_stacks *stks)
{
	if (len == 3 && com[0] == 'r' && com[1] == 'r'
		&& (com[2] == 'r' || com[2] == 'a'))
		res = cmd_app_rr(&stks->a);
	if (len == 3 && com[0] == 'r' && com[1] == 'r'
		&& (com[2] == 'r' || com[2] == 'b'))
		res = cmd_app_rr(&stks->b);
	return (res);
}

static int	cmd_app(char *com, t_stacks *stks)
{
	int	len;
	int	res;

	len = ft_strlen(com);
	res = 0;
	if (len == 2 && com[0] == 's' && (com[1] == 's' || com[1] == 'a'))
		res = cmd_app_s(&stks->a);
	if (len == 2 && com[0] == 's' && (com[1] == 's' || com[1] == 'b'))
		res = cmd_app_s(&stks->b);
	if (len == 2 && com[0] == 'p' && com[1] == 'a')
		res = cmd_app_p(&stks->b, &stks->a);
	if (len == 2 && com[0] == 'p' && com[1] == 'b')
		res = cmd_app_p(&stks->a, &stks->b);
	if (len == 2 && com[0] == 'r' && (com[1] == 'r' || com[1] == 'a'))
		res = cmd_app_r(&stks->a);
	if (len == 2 && com[0] == 'r' && (com[1] == 'r' || com[1] == 'b'))
		res = cmd_app_r(&stks->b);
	if (len == 3)
		res = cmd_len(len, res, com, stks);
	if (res == 0)
		return (0);
	return (1);
}

void	cmd_aap_cnt(char *com, int cnt, t_stacks *stks)
{
	int	i;

	i = ft_abs(cnt);
	while (i)
	{
		if (cmd_app(com, stks))
		{
			if (stks->cmd_print == 1)
			{
				cmd_print(com);
			}
			stks->cmd_cnt++;
		}
		else
			put_error(&stks, 0);
		i--;
	}
}
