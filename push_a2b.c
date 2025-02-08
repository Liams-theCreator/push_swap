/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a2b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:34:22 by imellali          #+#    #+#             */
/*   Updated: 2025/02/08 16:23:14 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_idx(t_lista *stack_a, int num)
{
	int	idx;
	t_lista *head;

	idx = 0;
	head = stack_a;
	while (head)
	{
		if (num == head->num)
			return (idx);
		idx++;
		head = head->next;
	}
	return (-1);
}

static int	minimum(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

static int	calcul_moves(t_lista *stack_a, int number, t_lista *stack_b, int position)
{
	int	cost_in_a;
	int	cost_in_b;
	int	index;

	index = find_idx(stack_a, number);
	cost_in_a = minimum(index, list_len(stack_a) - index);
	cost_in_b = minimum(position, list_len(stack_b) - position);

	return (cost_in_a + cost_in_b);
}

static void	perfom_ra(t_lista **stack_a, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		ra(stack_a, 1);
		i++;
	}
}

static void	perfom_rra(t_lista **stack_a, int index)
{
	int	len;

	len = list_len(*stack_a) - 1;
	while (len >= index)
	{
		rra(stack_a, 1);
		len--;
	}
}

static void	perfom_rb(t_lista **stack_b, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		rb(stack_b, 1);
		i++;
	}
}

static void	perfom_rrb(t_lista **stack_b, int index)
{
	int	len;

	len = list_len(*stack_b) - 1;
	while (len >= index)
	{
		rrb(stack_b, 1);
		len--;
	}
}

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

int	find_position(t_lista *stack_b, int num)
{
	int		position;
	int		largest;
	int		smallest;
	t_lista	*head;

	largest = find_largest(stack_b);
	smallest = find_smallest(stack_b);
	head = stack_b;
	position = 0;
	if (num > largest || num < smallest)
		return (find_idx(stack_b, largest));
	while (head->next)
	{
		if (head->num > num && num > head->next->num)
			return (position + 1);
		position++;
		head = head->next;
	}
	return (position + 1);
}

void    push_a2b(t_lista **stack_a, t_lista **stack_b)
{
	int	moves;
	int	cheap_moves;
	t_lista *node;
	t_lista *cheap_num;

	moves = 444444;
	cheap_num = NULL;
	node = *stack_a;
	while (node)
	{
		cheap_moves = calcul_moves(*stack_a, node->num, *stack_b, find_position(*stack_b, node->num));
		if (cheap_moves < moves)
		{
			moves = cheap_moves;
			cheap_num = node;
		}
		node = node->next;
	}
	shift_2top_a(stack_a, find_idx(*stack_a, cheap_num->num));
	shift_2top_b(stack_b, find_position(*stack_b, cheap_num->num));
	pb(stack_a, stack_b);
}
