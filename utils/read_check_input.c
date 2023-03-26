/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:00:53 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/03/25 05:25:26 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	read_input(t_list **stack_a, char **av, t_vars *m)
{
	char	**t;

	m->n = 0;
	m->sa_n = 0;
	while (av[++m->n])
	{
		t = ft_split(av[m->n], ' ');
		if (!t[0])
				exit_message(3, stack_a, NULL);
		m->i = -1;
		while (t[++m->i])
		{
			m->j = -1;
			while (t[m->i][++m->j])
			{
				if (m->j == 0 && (t[m->i][m->j] == '-' || t[m->i][m->j] == '+'))
					m->j++;
				if (!ft_isdigit(t[m->i][m->j]))
					exit_message(0, stack_a, NULL);
			}
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(t[m->i]), ++m->sa_n));
		}
		ft_clear(t, m->i);
	}
	return (check_duplicate(stack_a), final_pos(*stack_a));
}

void	check_duplicate(t_list **stack_a)
{
	t_list	*x;
	t_list	*y;

	x = *stack_a;
	while (x)
	{
		y = x->next;
		while (y)
		{
			if (y->content == x->content)
				exit_message(1, stack_a, NULL);
			y = y->next;
		}
		x = x->next;
	}
}

void	final_pos(t_list *stack_a)
{
	t_list	*x2;
	t_list	*min;
	int		i;

	i = 1;
	while (1)
	{
		min = NULL;
		x2 = stack_a;
		while (x2)
		{
			if (x2->final_pos == -1)
			{
				if (min == NULL)
					min = x2;
				if (x2->content < min->content)
					min = x2;
			}
			x2 = x2->next;
		}
		if (min == NULL)
			return ;
		min->final_pos = i++;
	}
}

void	edit_pos(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 1;
	if (stack_a)
	{
		while (stack_a)
		{
			stack_a->pos = i++;
			stack_a = stack_a->next;
		}
	}
	i = 1;
	if (stack_b)
	{
		while (stack_b)
		{
			stack_b->pos = i++;
			stack_b = stack_b->next;
		}
	}
	return ;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	while (s1[++i])
		s[i] = s1[i];
	while (s2[++j])
		s[i++] = s2[j];
	s[i] = '\0';
	return (s);
}
