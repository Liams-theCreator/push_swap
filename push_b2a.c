/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b2a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:34:29 by imellali          #+#    #+#             */
/*   Updated: 2025/02/14 02:36:44 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// int find_pos(t_lista *stack_a, int num)
// {
// 	int position;
// 	int largest;
// 	int smallest;
// 	t_lista *head;

// 	largest = find_largest(stack_a);
// 	smallest = find_smallest(stack_a);
// 	head = stack_a;
// 	position = 0;
// 	if (num > largest)
// 		return (find_idx(stack_a, largest) + 1);
// 	else if (num < smallest)
// 		return (find_idx(stack_a, smallest));
// 	while (head && head->next)
// 	{
// 		if (head->num < num && num < head->next->num)
// 			return (position + 1);
// 		position++;
// 		head = head->next;
// 	}
// 	return (position + 1);
// }

int find_pos(t_lista *stack_a, int num)
{
	int position;
	int largest;
	int smallest;
	int i;
	int j;
	t_lista *head;

	largest = find_largest(stack_a);
	smallest = find_smallest(stack_a);
	head = stack_a;
	position = 0;
	if (num > largest)
		return (find_idx(stack_a, largest) + 1);
	else if (num < smallest)
		return (find_idx(stack_a, smallest));
	i = 999999;
	while (head)
	{
		if (head->num > num && head->num < i)
		{
			i = head->num;
			j = position;
		}
		position++;
		head = head->next;
	}
	return (j == 0 ? 0 : position - (position - j));
}

void push_b2a(t_lista **stack_a, t_lista **stack_b)
{
	int position;

	while (*stack_b)
	{
		position = find_pos(*stack_a, (*stack_b)->num);
		// printf("position %d, number to push %d\n", position, (*stack_b)->num);
		// print_list(*stack_b);
		// print_list(*stack_a);
		shift_2top_a(stack_a, position);
		pa(stack_a, stack_b);
	}
}
