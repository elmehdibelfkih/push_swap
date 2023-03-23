/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:04:34 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/02/22 06:16:16 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*s2;

	i = ft_strlen(s1);
	j = -1;
	s2 = malloc(i * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	while (i >= ++j)
		s2[j] = s1[j];
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*s1;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	if (i < start)
		return (ft_calloc(1, 1));
	else if (i >= start + len)
		s1 = malloc(len + 1);
	else
		s1 = malloc(i - start + 1);
	if (!s1)
		return (NULL);
	while (len-- > 0 && s[start])
		s1[j++] = s[start++];
	s1[j] = '\0';
	return (s1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*s;
	int				i;
	unsigned char	*p;

	i = size * count;
	s = malloc(size * count);
	if (!s)
		return (NULL);
	p = (unsigned char *)s;
	while (i-- > 0)
		*p++ = '\0';
	return (s);
}

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (c);
	return (0);
}
