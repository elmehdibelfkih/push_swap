/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:01:19 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/05/10 07:05:11 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// void leaks(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_vars	m;

	stack_a = NULL;
	stack_b = NULL;
	m.sb_n = 0;
	m.ch_status = 0;
	m.sa_n = 0;
	m.n = 0;
	if (ac < 2)
		return (0);
	// atexit(leaks);
	read_input(&stack_a, av, &m);
	if (is_sorted(&stack_a, &m) == 1)
		exit_message(0, &stack_a, &stack_b, &m);
	n_of_chunks(&m);
	sort(&stack_a, &stack_b, &m);
	exit_message(0, &stack_a, &stack_b, &m);
}
