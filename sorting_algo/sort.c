/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 06:14:22 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/04/07 10:34:13 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	small_sort_3(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp->final_pos == 1 && tmp->next->final_pos == 3)
	{
		operation(stack_a, stack_b, m, "rra");
		operation(stack_a, stack_b, m, "sa");
	}
	else if (tmp->final_pos == 2 && tmp->next->final_pos == 1)
		operation(stack_a, stack_b, m, "sa");
	else if (tmp->final_pos == 2 && tmp->next->final_pos == 3)
		operation(stack_a, stack_b, m, "rra");
	else if (tmp->final_pos == 3 && tmp->next->final_pos == 2)
	{
		operation(stack_a, stack_b, m, "sa");
		operation(stack_a, stack_b, m, "rra");
	}
	else if (tmp->final_pos == 3 && tmp->next->final_pos == 1)
		operation(stack_a, stack_b, m, "ra");
	return ;
}

void	small_sort_4(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->final_pos == 4)
		{
			if (tmp->pos == 2)
				operation(stack_a, stack_b, m, "sa");
			else if (tmp->pos == 3)
			{
				operation(stack_a, stack_b, m, "rra");
				operation(stack_a, stack_b, m, "rra");
			}
			else if (tmp->pos == 4)
				operation(stack_a, stack_b, m, "rra");
		}
		tmp = tmp->next;
	}
	operation(stack_a, stack_b, m, "pb");
	small_sort_3(stack_a, stack_b, m);
	return (operation(stack_a, stack_b, m, "pa"),
		operation(stack_a, stack_b, m, "ra"));
}

void	small_sort_5(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->final_pos == 5)
		{
			if (tmp->pos == 2)
				operation(stack_a, stack_b, m, "sa");
			else if (tmp->pos == 3)
			{
				operation(stack_a, stack_b, m, "ra");
				operation(stack_a, stack_b, m, "sa");
			}
			else if (tmp->pos == 4)
			{
				operation(stack_a, stack_b, m, "rra");
				operation(stack_a, stack_b, m, "rra");
			}
			else if (tmp->pos == 5)
				operation(stack_a, stack_b, m, "rra");
		}
		tmp = tmp->next;
	}
	operation(stack_a, stack_b, m, "pb");
	small_sort_4(stack_a, stack_b, m);
	return (operation(stack_a, stack_b, m, "pa"),
		operation(stack_a, stack_b, m, "ra"));
}

void	best_instructions(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	m->chank = (m->sb_n / m->chunk_size) + 1;
	m->chank_start = ((m->chank - 1) * m->chunk_size) + 1;
	m->chank_end = (m->chank * m->chunk_size);
	m->op = node_pose(stack_a, m);
	while (m->chank_start > (*stack_a)->final_pos
		|| (*stack_a)->final_pos > m->chank_end)
	{		
		if (m->op == 1 && m->rb_status == 0)
			operation(stack_a, stack_b, m, "ra");
		else if (m->op == 1 && m->rb_status != 0)
		{
			operation(stack_a, stack_b, m, "rr");
			m->rb_status--;
		}
		// else if (m->op == -1 && m->rb_status != 0)
		// {
		// 	operation(stack_a, stack_b, m, "rra");
		// }
		else if (m->op == -1)
			operation(stack_a, stack_b, m, "rra");
	}
	return ;
}

void	small_sort(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	m->rb_status = 0;
	while (m->sa_n != 0)
	{
		best_instructions(stack_a, stack_b, m);
		operation(stack_a, stack_b, m, "pb");
		if ((*stack_b)->final_pos <= ((m->chank_start) + (m->chunk_size / 2)))
			m->rb_status++;
		while(m->rb_status > 0 && node_pose(stack_a, m) == -1)
		{
			operation(stack_a, stack_b, m, "rb");
			m->rb_status--;
		}
	}
	if ((*stack_b)->final_pos < ((m->chank_start) + (m->chunk_size / 2)))
		operation(stack_a, stack_b, m, "rb");
	push_to_stack_a(stack_a, stack_b, m);
	return ;
}

void	push_to_stack_a(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	while (m->sb_n)
	{
		if ((*stack_b)->final_pos == m->sb_n)
		{
			// printf("m->sb_n :%d\nfinal_pos:%d\ncontent:%d\n", m->sb_n, (*stack_b)->final_pos, (*stack_b)->content);
			operation(stack_a, stack_b, m, "pa");
		}
		else
		{	
			if (instructions_counter(stack_b, m, m->sb_n) == 1)
				operation(stack_a, stack_b, m, "rb");
			else
				operation(stack_a, stack_b, m, "rrb");
		}
	}
	return ;
}