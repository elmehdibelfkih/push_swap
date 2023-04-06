/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chanks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:42:42 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/04/06 09:12:11 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	n_of_chunks(t_vars *m)
{
	if (m->sa_n <= 5)
		m->n_chunks = 1;
	else if (m->sa_n <= 100)
		m->n_chunks = 5;
	else if (m->sa_n <= 500)
		m->n_chunks = 11;
	else
		m->n_chunks = 50;
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

// int instructions_counter(t_list **stack_a, t_vars *m, int j)
// {
// 	t_list	*tmp;

// 	tmp = *stack_a;
// 	while (tmp)
// 	{
// 		if (tmp->final_pos == j)
// 		{
// 			if ((tmp->pos) <= (m->sa_n / 2))
// 				return (1);
// 			else if ((tmp->pos) > m->sa_n / 2)
// 				return (-1);
// 			else
// 				return (0);
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }