/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 06:48:18 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/03/23 09:26:58 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_vars	m;

	stack_a = NULL;
	stack_b = NULL;
	m.sb_n = 0;
	m.ch_status = 1;
	if (ac < 2)
		return (0);
	read_input(&stack_a, av, &m);
	final_pos(stack_a);
	checker_read_input(&stack_a, &stack_b, &m);
	return (1);
}