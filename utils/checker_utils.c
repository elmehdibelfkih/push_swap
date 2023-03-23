/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:20:18 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/03/23 07:22:30 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	checker_read_input(char **argv, int argc, )
{
	char	*s;
	char	*c;
	int		fd;
	c = ft_strjoin(argv[2], "\n");
	if (argc <= 5)
		exit_message (0, vars);
	fd = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0777);
	s = get_next_line(0);
	while (s && !ft_strncmp(s, c, ft_strlen(c)))
	{
		write(fd, s, ft_strlen(s));
		free(s);
		s = get_next_line(0);
	}
	parsing_args(vars, argv + 1, argc - 1);
	vars->input = strdup("here_doc");
	vars->here_doc_status = 1;
	return (free(s), free(c));
	parsing_args(vars, argv, argc);
	vars->here_doc_status = 0;
	return ;
}
