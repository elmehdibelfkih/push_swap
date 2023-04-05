/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:58:58 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/04/05 03:18:51 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	exit_message(int i, t_list **stack_a, t_list **stack_b)
{
	char	**message;

	message = malloc(5 * sizeof(char *));
	message[0] = ft_strdup("Is not digit\n");
	message[1] = ft_strdup("Duplicate founded !\n");
	message[2] = ft_strdup("Sorted !!\n");
	message[3] = ft_strdup("Error\n");
	message[4] = NULL;
	write(1, message[i], strlen(message[i]));
	if (stack_a)
		ft_lstclear(stack_a);
	if (stack_b)
		ft_lstclear(stack_b);
	ft_clear(message, 3);
	exit(0);
}

void	print_operation(int i)
{
	char	**operation;

	operation = malloc(12 * sizeof(char *));
	operation[0] = ft_strdup("sa\n");
	operation[1] = ft_strdup("sb\n");
	operation[2] = ft_strdup("ss\n");
	operation[3] = ft_strdup("pa\n");
	operation[4] = ft_strdup("pb\n");
	operation[5] = ft_strdup("ra\n");
	operation[6] = ft_strdup("rb\n");
	operation[7] = ft_strdup("rr\n");
	operation[8] = ft_strdup("rra\n");
	operation[9] = ft_strdup("rrb\n");
	operation[10] = ft_strdup("rrr\n");
	operation[11] = NULL;
	write(1, operation[i], strlen(operation[i]));
	ft_clear(operation, 10);
	return ;
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
	else
		exit_message(3, stack_a, stack_b);
	return ;
}

int	is_sorted(t_list **stack_a, t_vars *m)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (m->sb_n != 0)
		return (-1);
	while (tmp)
	{
		if (tmp->final_pos != tmp->pos)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

// void	print_list(t_list *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d  : %d  : %d\n", stack->content, stack->final_pos, stack->pos);
// 		stack = stack->next;
// 	}
// 	return ;
// }
