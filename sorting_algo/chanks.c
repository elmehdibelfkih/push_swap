/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chanks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:42:42 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/05/08 06:11:40 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	n_of_chunks(t_vars *m)
{
	if (m->sa_n <= 5)
		m->n_chunks = 1;
	else if (m->sa_n <= 100)
		m->n_chunks = 4;
	else if (m->sa_n <= 200)
		m->n_chunks = 5;
	else if (m->sa_n <= 300)
		m->n_chunks = 6;
	else if (m->sa_n <= 400)
		m->n_chunks = 8;
	else if (m->sa_n <= 500)
		m->n_chunks = 9;
	else
		m->n_chunks = 18;
	m->chunk_size = m->sa_n / m->n_chunks;
	return ;
}

int	node_pose(t_list **stack_a, t_vars *m)
{
	t_list	*tmp;
	int		i;
	int		j;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		if (m->chank_start <= tmp->final_pos && tmp->final_pos <= m->chank_end)
		{
			if (i == 0)
				i = tmp->pos - 1;
			j = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (i <= m->sa_n - j + 1)
		return (1);
	return (-1);
}

int	instructions_counter(t_list **stack_b, t_vars *m, int j)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->final_pos == j)
		{
			if ((tmp->pos) <= (m->sb_n / 2))
				return (tmp->pos);
			else if ((tmp->pos) > m->sb_n / 2)
				return (-tmp->pos);
		}
		tmp = tmp->next;
	}
	return (-1);
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
		else if (m->op == -1)
			operation(stack_a, stack_b, m, "rra");
	}
	return ;
}
