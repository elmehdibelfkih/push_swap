/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:58:58 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/03/23 07:00:02 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	exit_message(int i, t_list **stack)
{
	char	**message;

	message = malloc(9 * sizeof(char *));
	message[0] = ft_strdup("is not digit");
	message[1] = ft_strdup("duplicate founded !");
	message[2] = ft_strdup("sorted !!");
	message[3] = NULL;
	write(1, message[i], strlen(message[i]));
	ft_lstclear(stack);
	ft_clear(message, 3);
	exit(0);
}

void	print_operation(int i)
{
	char	**operation;

	operation = malloc(12 * sizeof(char *));
	operation[0] = ft_strdup("sa");
	operation[1] = ft_strdup("sb");
	operation[2] = ft_strdup("ss");
	operation[3] = ft_strdup("pa");
	operation[4] = ft_strdup("pb");
	operation[5] = ft_strdup("ra");
	operation[6] = ft_strdup("rb");
	operation[7] = ft_strdup("rr");
	operation[8] = ft_strdup("rra");
	operation[9] = ft_strdup("rrb");
	operation[10] = ft_strdup("rrr");
	operation[11] = NULL;
	write(1, operation[i], strlen(operation[i]));
	ft_clear(operation, 10);
	write(1, "\n", 1);
}

void	print_list(t_list *stack)
{
	while (stack)
	{
		printf("%d  : %d  : %d\n", stack->content, stack->final_pos, stack->pos);
		stack = stack->next;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	operation(t_list **stack_a, t_list **stack_b, t_vars *m, char *s)
{
	if (ft_strncmp(s, "sa", 5))
		swap(stack_a, m, 0);
	else if (ft_strncmp(s, "sb", 5))
		swap(stack_b, m, 1);
	else if (ft_strncmp(s, "ss", 5))
		ss(stack_a, stack_b, m, 2);
	else if (ft_strncmp(s, "pa", 5))
		push(stack_a, stack_b, m, 3);
	else if (ft_strncmp(s, "pb", 5))
		push(stack_a, stack_b, m, 4);
	else if (ft_strncmp(s, "ra", 5))
		rotate(stack_a, stack_b, m, 5);
	else if (ft_strncmp(s, "rb", 5))
		rotate(stack_a, stack_b, m, 6);
	else if (ft_strncmp(s, "rr", 5))
		rotate(stack_a, stack_b, m, 7);
	else if (ft_strncmp(s, "rra", 5))
		reverse_rotate(stack_a, stack_b, m, 8);
	else if (ft_strncmp(s, "rrb", 5))
		reverse_rotate(stack_a, stack_b, m, 9);
	else if (ft_strncmp(s, "rrr", 5))
		reverse_rotate(stack_a, stack_b, m, 10);
	return ;
}

void	is_sorted(t_list **stack_a, t_vars *m)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (m->sb_n != 0)
		return ;
	while (tmp)
	{
		if (tmp->final_pos != tmp->pos)
			return ;
		tmp = tmp->next;
	}
	exit_message(2, stack_a);
}