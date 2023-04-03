/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:34:35 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/04/03 00:43:18 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*ft_lstnew(int i, int initial_pos)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = i;
	new->next = NULL;
	new->pos = initial_pos;
	new->final_pos = -1;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!new)
		return ;
	if (*lst == NULL)
		ft_lstadd_front(lst, new);
	else
	{
		p = ft_lstlast(*lst);
		p->next = new;
	}
	return ;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(*lst))
		new->next = NULL;
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
	return ;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*t;

	t = *lst;
	if (!*lst)
		return ;
	while (*lst)
	{
		t = (*lst)->next;
		free(*lst);
		*lst = t;
	}
	return ;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
