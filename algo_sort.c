/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:29:57 by imellali          #+#    #+#             */
/*   Updated: 2025/02/10 17:11:37 by imellali         ###   ########.fr       */
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

static void	shift_2top_b(t_lista **stack_b, int position)
{
	int	length;

	length = list_len(*stack_b) / 2;
	if (position <= length)
		perfom_rb(stack_b, position);
	else if (position > length)
		perfom_rrb(stack_b, position);
}

void	sorting_algorithm(t_lista **stack_a, t_lista **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (list_len(*stack_a) > 3)
	{
        if (sorted(*stack_a) == 0)
            break;
		push_a2b(stack_a, stack_b);
	}
	if ((sorted(*stack_a)) == -1 && list_len(*stack_a) == 3)
		sort_three(stack_a);
    shift_2top_b(stack_b, find_max(*stack_b));
	push_b2a(stack_a, stack_b);
	if (sorted(*stack_a) == -1)
		shift_2top_a(stack_a, find_idx(*stack_a, find_smallest(*stack_a)));
}