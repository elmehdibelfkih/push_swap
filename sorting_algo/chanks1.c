/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chanks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:24:08 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/05/08 01:27:41 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_to_stack_b(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	m->rb_status = 0;
	while (m->sa_n)
	{
		best_instructions(stack_a, stack_b, m);
		if ((*stack_a)->final_pos > ((m->chank_start) + (m->chunk_size / 2)))
			m->rb_status++;
		else
		{
			while (m->rb_status > 0)
			{
				operation(stack_a, stack_b, m, "rb");
				m->rb_status--;
			}	
		}
		operation(stack_a, stack_b, m, "pb");
	}
	if ((*stack_b)->final_pos <= ((m->chank_start) + (m->chunk_size / 2)))
		operation(stack_a, stack_b, m, "rb");
	return ;
}

void	push_to_stack_a(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	m->sw_status = 0;
	while (m->sb_n)
	{
		if (m->sw_status == 1 && (*stack_a)->final_pos == (m->sb_n + 2))
			best_swap(stack_a, stack_b, m);
		else if (((*stack_b)->final_pos == (m->sb_n + m->sw_status))
			|| ((*stack_b)->final_pos == (m->sb_n + m->sw_status - 1)))
		{
			operation(stack_a, stack_b, m, "pa");
			if ((*stack_a)->final_pos == (m->sb_n))
				m->sw_status = 1;
		}
		else
		{	
			if (instructions_counter(stack_b, m, best_push(stack_b, m)) > 0)
				operation(stack_a, stack_b, m, "rb");
			else
				operation(stack_a, stack_b, m, "rrb");
		}
	}
	if (m->sw_status == 1 && (*stack_a)->final_pos == (m->sb_n + 2))
		operation(stack_a, stack_b, m, "sa");
	return ;
}

int	best_push(t_list **stack_b, t_vars *m)
{
	int	max;
	int	next_max;

	if (m->sw_status == 0)
	{
		if (instructions_counter(stack_b, m, m->sb_n) < 0)
			max = m->sb_n + instructions_counter(stack_b, m, m->sb_n) + 1;
		else
			max = instructions_counter(stack_b, m, m->sb_n) - 1;
		if (instructions_counter(stack_b, m, m->sb_n - 1) < 0)
			next_max = m->sb_n
				+ instructions_counter(stack_b, m, m->sb_n - 1) + 1;
		else
			next_max = instructions_counter(stack_b, m, m->sb_n - 1) - 1;
	}
	else
		return (m->sb_n + 1);
	if (max >= next_max)
		return (m->sb_n - 1);
	return (m->sb_n);
}

void	best_swap(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	if (m->sb_n >= 2 && (*stack_b)->final_pos < (*stack_b)->next->final_pos)
	{
		operation(stack_a, stack_b, m, "ss");
		m->sw_status = 0;
	}
	else
	{
		operation(stack_a, stack_b, m, "sa");
		m->sw_status = 0;
	}
	return ;
}
