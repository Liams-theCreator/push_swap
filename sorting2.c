/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:23:31 by imellali          #+#    #+#             */
/*   Updated: 2025/02/02 17:19:28 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_min(t_lista *stack_a)
{
	int		min_num;
	int		its_index;
	int		counter;
	t_lista	*head;

	min_num = stack_a->num;
	its_index = 0;
	counter = 0;
	head = stack_a;

	while (head)
	{
		if (head->num < min_num)
		{
			min_num = head->num;
			its_index = counter;
		}
		counter++;
		head = head->next;
	}
	return (its_index);
}

static void	shift_to_push(t_lista **stack_a, t_lista **stack_b, int index)
{
	if (index == 0)
		pb(stack_a, stack_b);
	else if (index == 1)
	{
		sa(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else if (index == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else if (index == 3)
	{
		rra(stack_a, 1);
		pb(stack_a, stack_b);
	}
}

void	sort_four(t_lista **stack_a, t_lista **stack_b)
{
	int	min_index;

	min_index = find_min(*stack_a);
	shift_to_push(stack_a, stack_b, min_index);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}
