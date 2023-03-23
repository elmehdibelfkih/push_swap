/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:01:19 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/03/23 08:48:57 by ebelfkih         ###   ########.fr       */
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
	printf("stack_a\n");
	print_list(stack_a);
	printf("stack_b\n");
	print_list(stack_b);
	printf("--------------------------------\n");
	operation(&stack_a, &stack_b, &m, "pb");
	operation(&stack_a, &stack_b, &m, "pb");
	operation(&stack_a, &stack_b, &m, "rb");
	printf("--------------------------------\n");
	printf("stack_a\n");
	print_list(stack_a);
	printf("stack_b\n");
	print_list(stack_b);
	printf("--------------------------------\n");
}
