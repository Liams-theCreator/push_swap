/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:47:53 by imellali          #+#    #+#             */
/*   Updated: 2025/02/05 12:13:08 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_lista **stack, int msg)
{
	t_lista	*old_head;
	t_lista	*new_head;

	old_head = *stack;
	new_head = (*stack)->next;
	if (!(*stack) || !(*stack)->next)
		ft_error();
	old_head->next = new_head->next;
	new_head->next = old_head;
	*stack = new_head;
	if (msg == 1)
		write(1, "sa\n", 3);
}

void	sb(t_lista **stack, int msg)
{
	t_lista	*old_head;
	t_lista	*new_head;

	old_head = *stack;
	new_head = (*stack)->next;
	if (!(*stack) || !(*stack)->next)
		ft_error();
	old_head->next = new_head->next;
	new_head->next = old_head;
	*stack = new_head;
	if (msg == 1)
		write(1, "sb\n", 3);
}

void	ss(t_lista **stack_a, t_lista **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}

void	ra(t_lista **stack, int msg)
{
	t_lista	*old_head;
	t_lista	*current;
	t_lista	*new_head;

	current = *stack;
	old_head = *stack;
	new_head = (*stack)->next;
	if (!(*stack) || !(*stack)->next)
		ft_error();
	while (current->next)
		current = current->next;
	current->next = old_head;
	old_head->next = NULL;
	*stack = new_head;
	if (msg == 1)
		write(1, "ra\n", 3);
}

void	rb(t_lista **stack, int msg)
{
	t_lista	*old_head;
	t_lista	*current;
	t_lista	*new_head;

	current = *stack;
	old_head = *stack;
	new_head = (*stack)->next;
	if (!(*stack) || !(*stack)->next)
		ft_error();
	while (current->next)
		current = current->next;
	current->next = old_head;
	old_head->next = NULL;
	*stack = new_head;
	if (msg == 1)
		write(1, "rb\n", 3);
}

void	rr(t_lista **stack_a, t_lista **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}

void	rra(t_lista **stack, int msg)
{
	t_lista	*old_head;
	t_lista	*new_head;
	t_lista	*current;
	t_lista	*temp;

	current = *stack;
	old_head = *stack;
	if (!(*stack) || !(*stack)->next)
		ft_error();
	while (current->next)
	{
		if (current->next->next == NULL)
			temp = current;
		current = current->next;
	}
	new_head = current;
	new_head->next = old_head;
	temp->next = NULL;
	*stack = new_head;
	if (msg == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_lista **stack, int msg)
{
	t_lista	*old_head;
	t_lista	*new_head;
	t_lista	*current;
	t_lista	*temp;

	current = *stack;
	old_head = *stack;
	if (!(*stack) || !(*stack)->next)
		ft_error();
	while (current->next)
	{
		if (current->next->next == NULL)
			temp = current;
		current = current->next;
	}
	new_head = current;
	new_head->next = old_head;
	temp->next = NULL;
	*stack = new_head;
	if (msg == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_lista **stack_a, t_lista **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}

void	pb(t_lista **stack_a, t_lista **stack_b)
{
	t_lista	*head;
	t_lista	*new_head;

	head = *stack_a;
	new_head = (*stack_a)->next;
	ft_create_node(stack_b, head->num);
	*stack_a = new_head;
	free(head);
	write(1, "pb\n", 3);
}

void	pa(t_lista **stack_a, t_lista **stack_b)
{
	t_lista	*head;
	t_lista	*new_head;

	head = *stack_b;
	new_head = (*stack_b)->next;
	ft_create_node(stack_a, head->num);
	*stack_b = new_head;
	free(head);
	write(1, "pa\n", 3);
}
