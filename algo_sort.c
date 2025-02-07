/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:29:57 by imellali          #+#    #+#             */
/*   Updated: 2025/02/07 20:08:45 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting_algorithm(t_lista **stack_a, t_lista **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	rb(stack_b, 1);
	while (list_len(*stack_a) > 3)
		push_a2b(stack_a, stack_b);
	if ((sorted(*stack_a)) == -1)
		sort_three(stack_a);
	// push_b2a(stack_a, stack_b);
}
