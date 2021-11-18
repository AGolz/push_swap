/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:54:03 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/24 17:05:57 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/checker.h"

int	main(int argc, char **argv)
{
	t_stacks	*stks;
	char		*cr_com;

	cr_com = NULL;
	stks = create_stacks(argc, argv);
	stks->cmd_print = 0;
	if (stks->a == NULL)
		exit(free_stks(&stks, 0));
	while (get_next_line_ps(0, &cr_com))
	{
		cmd_aap_cnt(cr_com, 1, stks);
		if (cr_com)
			free(cr_com);
	}
	if (sort_stacks_check(stks))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (free_stks(&stks, 0));
}
