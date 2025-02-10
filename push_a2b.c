/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a2b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:34:22 by imellali          #+#    #+#             */
/*   Updated: 2025/02/10 15:19:07 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	minimum(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

static int	calcul_moves(t_lista *stack_a, int num, t_lista *stack_b, int pos)
{
	int	cost_in_a;
	int	cost_in_b;
	int	index;

	index = find_idx(stack_a, num);
	cost_in_a = minimum(index, list_len(stack_a) - index);
	cost_in_b = minimum(pos, list_len(stack_b) - pos);
	return (cost_in_a + cost_in_b);
}

void	perfom_ra(t_lista **stack_a, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		ra(stack_a, 1);
		i++;
	}
}

void	perfom_rra(t_lista **stack_a, int index)
{
	int	len;

	len = list_len(*stack_a) - 1;
	while (len >= index)
	{
		rra(stack_a, 1);
		len--;
	}
}

void	perfom_rb(t_lista **stack_b, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		rb(stack_b, 1);
		i++;
	}
}

void	perfom_rrb(t_lista **stack_b, int index)
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

static void	shift_and_push(t_lista **stack_a, t_lista **stack_b, int number)
{
	int	index_a;
	int	position_b;
	int	length_a;
	int	length_b;

	index_a = find_idx(*stack_a, number);
	position_b = find_position(*stack_b, number);
	length_a = list_len(*stack_a);
	length_b = list_len(*stack_b);
	while (index_a > 0 && position_b > 0 && index_a <= length_a / 2 && position_b <= length_b / 2)
	{
		rr(stack_a, stack_b);
		index_a--;
		position_b--;
	}
	while (index_a < length_a && position_b < length_b && index_a > length_a / 2 && position_b > length_b / 2)
	{
		rrr(stack_a, stack_b);
		index_a++;
		position_b++;
	}
}

void	push_a2b(t_lista **stack_a, t_lista **stack_b)
{
	int		moves;
	int		cheap_moves;
	t_lista	*node;
	t_lista	*cheap_num;

	moves = 44444444;
	cheap_num = NULL;
	node = *stack_a;
	while (node)
	{
		cheap_moves = calcul_moves(*stack_a, node->num, *stack_b,
				find_position(*stack_b, node->num));
		if (cheap_moves < moves)
		{
			moves = cheap_moves;
			cheap_num = node;
		}
		node = node->next;
	}
	shift_and_push(stack_a, stack_b, cheap_num->num);
	shift_2top_a(stack_a, find_idx(*stack_a, cheap_num->num));
	shift_2top_b(stack_b, find_position(*stack_b, cheap_num->num));
	pb(stack_a, stack_b);
}
