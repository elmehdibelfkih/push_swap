/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 06:14:22 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/04/30 00:10:47 by ebelfkih         ###   ########.fr       */
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


void	push_to_stack_b(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	m->rb_status = 0;
	while (m->sa_n)
	{
		// if (m->sa_n <= 400 && (m->sb_n % m->chunk_size) == 0)
		// 	n_of_chunks(m);
		// else if (m->sa_n <= 300 && (m->sb_n % m->chunk_size) == 0)
		// 	n_of_chunks(m);
		// else if (m->sa_n <= 200 && (m->sb_n % m->chunk_size) == 0)
		// 	n_of_chunks(m);
		// else if (m->sa_n <= 100 && (m->sb_n % m->chunk_size) == 0)
		// 	n_of_chunks(m);
		best_instructions(stack_a, stack_b, m);
		operation(stack_a, stack_b, m, "pb");
		if ((*stack_b)->final_pos < ((m->chank_start) + (m->chunk_size / 2)))
			m->rb_status++;
		else
		{
			while(m->rb_status > 0 && node_pose(stack_a, m) == -1)
			{
				operation(stack_a, stack_b, m, "rb");
				m->rb_status--;
			}
				
		}
	}
	if ((*stack_b)->final_pos < ((m->chank_start) + (m->chunk_size / 2)))
		operation(stack_a, stack_b, m, "rb");
	return ;
}

void	push_to_stack_a(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	m->sw_status = 0;
	while (m->sb_n)
	{
		if (m->sw_status == 1 && (*stack_a)->final_pos == (m->sb_n + 2))
		{
			operation(stack_a, stack_b, m, "sa");
			m->sw_status = 0;
		}
		else if (((*stack_b)->final_pos == (m->sb_n + m->sw_status)) || ((*stack_b)->final_pos == (m->sb_n + m->sw_status - 1)))
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
	return ;
}

int	best_push(t_list **stack_b, t_vars *m)
{
	int max;
	int	next_max;

	if (m->sw_status == 0)
	{
		if (instructions_counter(stack_b, m, m->sb_n) < 0)
			max = m->sb_n + instructions_counter(stack_b, m, m->sb_n) + 1;
		else
			max = instructions_counter(stack_b, m, m->sb_n) - 1;
		if (instructions_counter(stack_b, m, m->sb_n - 1) < 0)
			next_max = m->sb_n + instructions_counter(stack_b, m, m->sb_n - 1) + 1;
		else
			next_max = instructions_counter(stack_b, m, m->sb_n - 1) - 1;
	}
	else
		return (m->sb_n + 1);
	if (max >= next_max)
		return (m->sb_n - 1);
	return (m->sb_n);
}

void	sort(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	if (m->sa_n == 3)
		small_sort_3(stack_a, stack_b, m);
	if (m->sa_n == 4)
		small_sort_4(stack_a, stack_b, m);
	if (m->sa_n == 5)
		small_sort_5(stack_a, stack_b, m);
	if (m->sa_n >= 6)
	{
		push_to_stack_b(stack_a, stack_b, m);
		push_to_stack_a(stack_a, stack_b, m);
	}
	if (m->sa_n == 2 && is_sorted(stack_a, m) == -1)
		operation(stack_a, stack_b, m, "sa");
	return ;
}
