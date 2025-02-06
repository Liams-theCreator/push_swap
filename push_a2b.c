/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a2b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:34:22 by imellali          #+#    #+#             */
/*   Updated: 2025/02/06 18:47:17 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	case_one(t_lista **stack_a, t_lista **stack_b, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		rb(stack_b, 1);
		i++;
	}
	pb(stack_a, stack_b);
	i = 0;
	while (i < position)
	{
		rrb(stack_b, 1);
		i++;
	}
}

static void	case_two(t_lista **stack_a, t_lista **stack_b, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		rrb(stack_b, 1);
		i++;
	}
	pb(stack_a, stack_b);
	i = 0;
	while (i < position)
	{
		rb(stack_b, 1);
		i++;
	}
}

static void	exec_moves(t_lista **stack_a, t_lista **stack_b, int position, int length)
{
	int	len;

	len = length / 2;
	if (position == 0)
	{
		pb(stack_a, stack_b);
		rb(stack_b, 1);
	}
	else if (position <= len)
		case_one(stack_a, stack_b, position);
	else
		case_two(stack_a, stack_b, position);
}

void    push_a2b(t_lista **stack_a, t_lista **stack_b)
{
    int position;

	while (list_len(*stack_a) > 3)
	{
		position = find_position(*stack_b, (*stack_a)->num);
		exec_moves(stack_a, stack_b, position, list_len(*stack_b));
	}
}
