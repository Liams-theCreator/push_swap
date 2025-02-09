/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:06:48 by imellali          #+#    #+#             */
/*   Updated: 2025/02/09 11:08:22 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_idx(t_lista *stack_a, int num)
{
	int		idx;
	t_lista	*head;

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

int	find_max(t_lista *stack_a)
{
	int		max_num;
	int		its_index;
	int		counter;
	t_lista	*head;

	max_num = stack_a->num;
	its_index = 0;
	counter = 0;
	head = stack_a;
	while (head)
	{
		if (head->num > max_num)
		{
			max_num = head->num;
			its_index = counter;
		}
		counter++;
		head = head->next;
	}
	return (its_index);
}

int	find_min(t_lista *stack_a)
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

int	find_largest(t_lista *stack)
{
	int		largest;
	t_lista	*head;

	largest = stack->num;
	head = stack;
	while (head)
	{
		if (head->num > largest)
			largest = head->num;
		head = head->next;
	}
	return (largest);
}

int	find_smallest(t_lista *stack)
{
	int		smallest;
	t_lista	*head;

	smallest = stack->num;
	head = stack;
	while (head)
	{
		if (head->num < smallest)
			smallest = head->num;
		head = head->next;
	}
	return (smallest);
}
