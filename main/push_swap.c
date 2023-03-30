/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:01:19 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/03/29 15:30:44 by ebelfkih         ###   ########.fr       */
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
	m.ch_status = 0;
	if (ac < 3)
		return (0);
	read_input(&stack_a, av, &m);
	if (is_sorted(&stack_a, &m) == 1)
		exit_message(2, &stack_a, &stack_b);
	small_sort_3(&stack_a, &stack_b, &m);
}
	// printf("--------------------------------\n");
	// printf("stack_a\n");
	// print_list(stack_a);
	// printf("stack_b\n");
	// print_list(stack_b);
	// printf("--------------------------------\n");