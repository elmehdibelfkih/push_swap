/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 05:33:33 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/02/22 06:16:45 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap(t_list **stack, t_vars *m, int i)
{
	t_list	*tmp;

	tmp = (*stack);
	if ((i == 0 && m->sa_n < 2) || (i == 1 && m->sb_n < 2)
		|| (i != 0 && i != 1))
		return ;
	m->c = tmp->content;
	m->f = tmp->final_pos;
	tmp->content = tmp->next->content;
	tmp->final_pos = tmp->next->final_pos;
	tmp->next->content = m->c;
	tmp->next->final_pos = m->f;
	if (i == 0 || i == 1)
		print_operation(i);
	return ;
}

void	ss(t_list **stack_a, t_list **stack_b, t_vars *m, int i)
{
	if (m->sa_n < 2 || m->sb_n < 2)
		return ;
	swap(stack_a, m, i);
	swap(stack_b, m, i);
	print_operation(i);
	return ;
}

void	push(t_list **stack_a, t_list **stack_b, t_vars *m, int i)
{
	t_list	*tmp;

	if ((i == 4 && m->sa_n == 0) || (i == 3 && m->sb_n == 0))
		return ;
	if (i == 4)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_lstadd_front(stack_b, tmp);
		m->sa_n--;
		m->sb_n++;
	}
	else if (i == 3)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_lstadd_front(stack_a, tmp);
		m->sa_n++;
		m->sb_n--;
	}
	print_operation(i);
	edit_pos(*stack_a, *stack_b);
	return ;
}

void	rotate(t_list **stack_a, t_list **stack_b, t_vars *m, int i)
{
	t_list	*tmp;

	if (i == 7 && (m->sa_n < 2 || m->sb_n < 2))
		return ;
	if (i == 5 || i == 7)
	{
		tmp = *stack_a;
		if (m->sa_n == 0)
			return ;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack_a, tmp);
	}
	if (i == 6 || i == 7)
	{
		tmp = *stack_b;
		if (m->sb_n == 0)
			return ;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack_b, tmp);
	}
	print_operation(i);
	edit_pos(*stack_a, *stack_b);
	return ;
}

void	reverse_rotate(t_list **stack_a, t_list **stack_b, t_vars *m, int i)
{
	t_list	*tmp;

	if (((i == 8 && m->sa_n < 2) || (i == 9 && m->sb_n < 2))
		|| (i == 10 && (m->sa_n < 2 || m->sb_n < 2)))
		return ;
	if (i == 8 || i == 10)
	{
		tmp = *stack_a;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front(stack_a, tmp->next);
		tmp->next = NULL;
	}
	if (i == 9 || i == 10)
	{
		tmp = *stack_b;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front(stack_b, tmp->next);
		tmp->next = NULL;
	}
	print_operation(i);
	edit_pos(*stack_a, *stack_b);
	return ;
}
