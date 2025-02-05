/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a2b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:34:22 by imellali          #+#    #+#             */
/*   Updated: 2025/02/05 20:43:32 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	case_one(t_lista **stack_a, t_lista **stack_b, int position)
{
	int	i;

	i = 1;
	while (i <= position)
	{
		rb(stack_b, 1);
		i++;
	}
	pb(stack_a, stack_b);
	i = 1;
	while (i <= position)
	{
		rrb(stack_b, 1);
		i++;
	}
}

static void	case_two(t_lista **stack_a, t_lista **stack_b, int position)
{
	int	i;

	i = 1;
	while (i <= position)
	{
		rrb(stack_b, 1);
		i++;
	}
	pb(stack_a, stack_b);
	i = 1;
	while (i <= position)
	{
		rb(stack_b, 1);
		i++;
	}
}

static void	case_three(t_lista **stack_a, t_lista **stack_b)
{
	pb(stack_a, stack_b);
	rb(stack_b, 1);
}

static void	exec_moves(t_lista **stack_a, t_lista **stack_b, int position, int length)
{
	int	len;

	len = length / 2;
	if (position == 0)
		pb(stack_a, stack_b);
	else if (position == length)
		case_three(stack_a, stack_b);
	else if (position < len)
		case_two(stack_a, stack_b, position);
	else
		case_one(stack_a, stack_b, position);
}

void    push_a2b(t_lista **stack_a, t_lista **stack_b)
{
    int len;
    int position;

	len = list_len(*stack_a);
	rb(stack_b, 1);
	while (len > 3)
	{
		position = find_position(*stack_b, (*stack_a)->num);
		printf("pos : %d\n", position);
		exec_moves(stack_a, stack_b, position, list_len(*stack_b));
		len--;
	}
}
