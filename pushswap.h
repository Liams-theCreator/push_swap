/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:32:41 by imellali          #+#    #+#             */
/*   Updated: 2025/02/03 14:37:03 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct list_a
{
	int				num;
	struct list_a	*next;
}	t_lista;

// string functions
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str, char **array, t_lista **list);
char	*ft_strdup(const char *s);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);

// input functions
t_lista	*ft_parsing(int argc, char **argv);

// linked list functions
t_lista	*ft_create_node(t_lista **head, int num);
void	ft_add_to_list(t_lista **head, char **array, int num);

// error handling functions
void	ft_error(void);
void	free_array(char **array);
void	free_list(t_lista **head);
void	exiting(char **array, t_lista **list);
int		sorted(t_lista	*stack);

// operations functions
void	sa(t_lista **stack, int msg);
void	sb(t_lista **stack, int msg);
void	ss(t_lista **stack_a, t_lista **stack_b);
void	ra(t_lista **stack, int msg);
void	rb(t_lista **stack, int msg);
void	rr(t_lista **stack_a, t_lista **stack_b);
void	rra(t_lista **stack, int msg);
void	rrb(t_lista **stack, int msg);
void	rrr(t_lista **stack_a, t_lista **stack_b);
void	pa(t_lista **stack_a, t_lista **stack_b);
void	pb(t_lista **stack_a, t_lista **stack_b);

// sorting functions
void	sort_two(t_lista **stack_a);
void	sort_three(t_lista **stack_a);
void	sort_four(t_lista **stack_a, t_lista **stack_b);
void	sort_five(t_lista **stack_a, t_lista **stack_b);

// utils functions
int	find_max(t_lista *stack_a);
int	find_min(t_lista *stack_a);

#endif
