/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:04:10 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/04/05 03:17:48 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list {
	int				content;
	int				pos;
	int				final_pos;
	struct s_list	*next;
}				t_list;

typedef struct s_vars {
	int	sa_n;
	int	sb_n;
	int	ch_status;
	int	n_of_shunks;
	int	shunk_size;
	int	shunk_n;
	int	c;
	int	f;
	int	i;
	int	j;
	int	n;
}				t_vars;

void	exit_message(int i, t_list **stack, t_list **stack_b);
t_list	*ft_lstnew(int i, int initial_pos);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		n_of_world(char const *s, char c);
int		ft_clear(char **spl, int p);
int		plen(char **spl, const char *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	check_duplicate(t_list **stack_a);
void	swap(t_list **stack, t_vars *m, int i);
void	read_input(t_list **stack, char **av, t_vars *m);
void	print_operation(int i);
void	final_pos(t_list *stack_a);
void	push(t_list **stack_a, t_list **stack_b, t_vars *m, int i);
void	ss(t_list **stack_a, t_list **stack_b, t_vars *m, int i);
void	edit_pos(t_list *stack_a, t_list *stack_b);
void	rotate(t_list **stack_a, t_list **stack_b, t_vars *m, int i);
void	reverse_rotate(t_list **stack_a, t_list **stack_b, t_vars *m, int i);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	operation(t_list **stack_a, t_list **stack_b, t_vars *m, char *s);
int		is_sorted(t_list **stack_a, t_vars *m);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_is_first(char const *s1, char const *set);
int		ft_is_last(char const *s1, char const *set);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchrp(const char *s, int c);
void	checker_read_input(t_list **stack_a, t_list **stack_b, t_vars *m);
void	small_sort_3(t_list **stack_a, t_list **stack_b, t_vars *m);
void	small_sort_4(t_list **stack_a, t_list **stack_b, t_vars *m);
void	small_sort_5(t_list **stack_a, t_list **stack_b, t_vars *m);
void	small_sort(t_list **stack_a, t_list **stack_b, t_vars *m);
void	print_list(t_list *stack);
void	n_of_chunks(t_vars *m);
int		node_pose(t_list **stack_a, t_vars *m, int j);
#endif