/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:53:08 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/03/23 09:09:50 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_is_first(char const *s1, char const *set)
{
	int	i;

	i = -1;
	while (s1[++i])
		if (!ft_strchrp(set, s1[i]))
			return (i);
	return (-1);
}

int	ft_is_last(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1);
	while (s1[--i])
		if (!ft_strchrp(set, s1[i]))
			return (i);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	if (ft_is_first(s1, set) == -1)
		return (ft_strdup(""));
	return (ft_substr(s1, ft_is_first(s1, set),
			ft_is_last(s1, set) - ft_is_first(s1, set) + 1));
}

char	*ft_strchrp(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return (str);
	return (NULL);
}
