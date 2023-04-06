/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 06:14:22 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/04/06 09:47:03 by ebelfkih         ###   ########.fr       */
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

void	small_sort(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	m->rb_status = 0;
	while (m->sa_n != 0)
	{
		m->chank = (m->sb_n / m->chunk_size) + 1;
		m->chank_start = ((m->chank - 1) * m->chunk_size) + 1;
		m->chank_end = (m->chank * m->chunk_size);
		m->op = node_pose(stack_a, m);
		while (m->chank_start > (*stack_a)->final_pos || (*stack_a)->final_pos > m->chank_end)
		{
			// best_instructions(stack_a, stack_a, m);
			if (m->op == 1 && m->rb_status == 0)
			{
				operation(stack_a, stack_b, m, "ra");
			}
			else if (m->op == 1 && m->rb_status == 1)
			{
				operation(stack_a, stack_b, m, "rr");
				m->rb_status = 0;
			}
			else if (m->op == -1 && m->rb_status == 1)
			{
				operation(stack_a, stack_b, m, "rra");
				operation(stack_a, stack_b, m, "rb");
				m->rb_status = 0;
			}
			else if (m->op == -1 && m->rb_status == 0)
			{
				operation(stack_a, stack_b, m, "rra");
			}
			// else if (m->rb_status == 1)
			// {
			// 	operation(stack_a, stack_b, m, "rb");
			// 	m->rb_status = 0;
			// }
	}
	if (m->rb_status == 1)
	{
		operation(stack_a, stack_b, m, "rb");
		m->rb_status = 0;
	}
	operation(stack_a, stack_b, m, "pb");
	if ((*stack_b)->final_pos <= ((m->chank_end) - (m->chunk_size / 2)))
	{
		m->rb_status = 1;
			// operation(stack_a, stack_b, m, "rr");
	}
	}
	return ;
}

int	best_instructions(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	if (m->op == 1 && m->rb_status == 0)
	{
		operation(stack_a, stack_b, m, "ra");
		return (1);
	}
	else if (m->op == 1 && m->rb_status == 1)
	{
		operation(stack_a, stack_b, m, "rr");
		m->rb_status = 0;
		return (1);
	}
	else if (m->op == -1 && m->rb_status == 1)
	{
		operation(stack_a, stack_b, m, "rra");
		operation(stack_a, stack_b, m, "rb");
		m->rb_status = 0;
		return (1);
	}
	else if (m->op == -1 && m->rb_status == 0)
	{
		operation(stack_a, stack_b, m, "rra");
		return (1);
	}
	else if (m->rb_status == 1)
		operation(stack_a, stack_b, m, "rb");
	return (1);		
}


	// if (m->op == 1)
	// 	operation(stack_a, stack_b, m, "ra");