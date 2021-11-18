/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 10:43:15 by cfiora            #+#    #+#             */
/*   Updated: 2021/10/24 15:39:30 by cfiora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				val;
	int				i;
	int				sort;
	struct s_stack	*next;
}						t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*max_sort;
	int				len_a;
	int				len_b;
	int				opt_a;
	int				opt_b;
	int				opt_pl;
	int				tmp_a;
	int				tmp_b;
	int				tmp_pl;
	int				cmd_print;
	int				cmd_cnt;
}						t_stacks;

int			get_count_nod(t_stack *stks);
t_stack		*create_new_nod(int val);
t_stack		*get_last_nod(t_stack *stack);
t_stacks	*create_stacks(int argc, char **argv);

int			free_stks(t_stacks **stks, int ret_num);
int			stk_set_tmp_cmd(t_stacks *stks, t_stack *tmp_b);
void		stk_copy_tmp_opt_cmd(t_stacks *stks);
void		put_error(t_stacks **stk, int ret_num);

void		push_back(t_stack **stack, t_stack *new);
void		push_front(t_stack **stack, t_stack *new);
t_stack		*push_back_int(t_stack **stack, int val);

t_stack		*pp_back(t_stack **stack);
t_stack		*pp_front(t_stack **stack);

void		stack_norm(t_stacks *stks);
void		nod_b_to_a(t_stacks	*stks);
void		stk_a_to_b(t_stacks	*stks);
void		stk_b_to_a(t_stacks	*stks);
void		stk_a_min_top(t_stacks *stks);

void		cmd_aap_cnt(char *com, int cnt, t_stacks *stks);

int			cmd_app_s(t_stack **stk);
int			cmd_app_r(t_stack **stk);
int			cmd_app_rr(t_stack **stk);
int			cmd_app_p(t_stack **st_dst, t_stack **st_src);

int			nod_itr_up(int stk_len, int nod_i);
int			nod_b_to_a_count(int a, int b, int plc_b);
int			get_nod_place_i(t_stack *stk, int nod_val);
void		set_index(t_stack *stk);
t_stack		*get_max_sort(t_stack *stk);

int			sort_stacks(t_stacks *stks);
int			sort_stacks_check(t_stacks *stks);
int			not_dubl(t_stack *stk, int val);
int			valid_int(int val_i, char *val_c);

#endif