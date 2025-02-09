/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:29:57 by imellali          #+#    #+#             */
/*   Updated: 2025/02/09 15:28:10 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	shift_2top_a(t_lista **stack_a, int index)
{
	int	length;

	length = list_len(*stack_a) / 2;
	if (index <= length)
		perfom_ra(stack_a, index);
	else if (index > length)
		perfom_rra(stack_a, index);
}

void	sorting_algorithm(t_lista **stack_a, t_lista **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (list_len(*stack_a) > 3)
		push_a2b(stack_a, stack_b);
	if ((sorted(*stack_a)) == -1)
		sort_three(stack_a);
	push_b2a(stack_a, stack_b);
	if ((sorted(*stack_a)) == -1)
		shift_2top_a(stack_a, find_idx(*stack_a, find_smallest(*stack_a)));
}
