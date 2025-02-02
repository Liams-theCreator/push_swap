/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:23:31 by imellali          #+#    #+#             */
/*   Updated: 2025/02/02 19:11:41 by imellali         ###   ########.fr       */
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

static void	shift_to_push4(t_lista **stack_a, t_lista **stack_b, int index)
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

static void	shift_to_push5(t_lista **stack_a, t_lista **stack_b, int index)
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
		rra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else if (index == 4)
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

void	sort_five(t_lista **stack_a, t_lista **stack_b)
{
	int	num1_idx;
	int	num2_idx;

	num1_idx = find_min(*stack_a);
	shift_to_push5(stack_a, stack_b, num1_idx);
	num2_idx = find_min(*stack_a);
	shift_to_push4(stack_a, stack_b, num2_idx);
	sort_three(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
