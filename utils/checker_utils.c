/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:20:18 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/03/25 06:04:41 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	checker_read_input(t_list **stack_a, t_list **stack_b, t_vars *m)
{
	char	*s;
	char	*c;

	s = get_next_line(0);
	c = ft_strtrim(s, "\n");
	while (s)
	{
		operation(stack_a, stack_b, m, c);
		free(s);
		free(c);
		s = get_next_line(0);
		c = ft_strtrim(s, "\n");
	}
	if (is_sorted(stack_a, m) == 1 && m->sb_n == 0)
		write(1, "ok\n", 4);
	else
		write(1, "ko\n", 4);
	return (free(s), free(c));
}
