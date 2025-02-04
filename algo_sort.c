/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:29:57 by imellali          #+#    #+#             */
/*   Updated: 2025/02/03 17:09:04 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting_algorithm(t_lista **stack_a, t_lista **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while ((list_len(*stack_a)) != 3)
	{
		// implementing sorting algo until 3 remaining on stack
	}
	if ((sorted(*stack_a)) == -1)
		sort_three(stack_a);
	while (stack_b)
		pa(stack_a, stack_b);
}
