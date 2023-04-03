/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shanks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:42:42 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/04/03 00:56:56 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	n_of_shunks(t_vars *m)
{
	if (m->sa_n <= 5)
		m->n_of_shunks = 1;
	else if (m->sa_n <= 100)
		m->n_of_shunks = 5;
	else if (m->sa_n <= 500)
		m->n_of_shunks = 11;
	else
		m->n_of_shunks = 100;
	m->shunk_size = m->sa_n / m->n_of_shunks;
	return ;
}

// int	shunk(t_list **stack_a, t_list **stack_b, t_vars *m)
// {
// 	int i;
// 	t_list *tmp;

// 	i = 0;
// 	tmp = *stack_a;
// 	m->shunk_n =  m->shunk_size / m->sb_n;
// 	while (m->sb_n <= )
	
// }

int	node_pose(t_list **stack_a, t_vars *m, int j)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->final_pos == j)
		{
			if (tmp->pos / 2 <= m->sa_n / 2)
				return (1);
			else if (tmp->pos / 2 >= m->sa_n / 2)
				return (-1);
			else
				return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}