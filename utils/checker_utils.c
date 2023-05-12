/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:20:18 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/05/12 16:38:31 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	checker_read_input(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	m->s = get_next_line(0);
	m->tr = ft_strtrim(m->s, "\n");
	while (m->s)
	{
		if (no_segmentation_fault(m))
			operation(stack_a, stack_b, m, m->tr);
		free(m->s);
		free(m->tr);
		m->s = get_next_line(0);
		m->tr = ft_strtrim(m->s, "\n");
	}
	if (is_sorted(stack_a, m) == 1 && m->sb_n == 0)
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
	return (free(m->s), free(m->tr));
}

int	no_segmentation_fault(t_vars *m )
{
	if (ft_strncmp(m->s, "sa\n", 5) && m->sa_n < 2)
		return (0);
	else if (ft_strncmp(m->s, "sb\n", 5) && m->sb_n < 2)
		return (0);
	else if (ft_strncmp(m->s, "ss\n", 5) && (m->sa_n < 2 || m->sb_n < 2))
		return (0);
	else if (ft_strncmp(m->s, "pa\n", 5) && m->sb_n == 0)
		return (0);
	else if (ft_strncmp(m->s, "pb\n", 5) && m->sa_n == 0)
		return (0);
	else if (ft_strncmp(m->s, "ra\n", 5) && m->sa_n < 2)
		return (0);
	else if (ft_strncmp(m->s, "rb\n", 5) && m->sb_n < 2)
		return (0);
	else if (ft_strncmp(m->s, "rr\n", 5) && (m->sa_n < 2 || m->sb_n < 2))
		return (0);
	else if (ft_strncmp(m->s, "rra\n", 5) && m->sa_n < 2)
		return (0);
	else if (ft_strncmp(m->s, "rrb\n", 5) && m->sb_n < 2)
		return (0);
	else if (ft_strncmp(m->s, "rrr\n", 5) && (m->sa_n < 2 || m->sb_n < 2))
		return (0);
	return (1);
}