/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:50:50 by imellali          #+#    #+#             */
/*   Updated: 2025/01/30 18:24:41 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

static size_t	print_list(t_lista *h)
{
	size_t	nodes;

	nodes = 0;
	while (h != NULL)
	{
		printf("  [ %d ]  \n", h->num);
		h = h->next;
		nodes++;
	}
	printf("\n");
	return (nodes);
}

int	main(int argc, char **argv)
{
	t_lista	*stack_a;
	t_lista	*stack_b;

	if (argc <= 1)
		ft_error();
	stack_b = NULL;
	stack_a = ft_parsing(argc, argv);

	print_list(stack_a);
	
	pb(&stack_a, &stack_b);

	print_list(stack_a);
	print_list(stack_b);

	pa(&stack_a, &stack_b);
	print_list(stack_a);
	print_list(stack_b);
	
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
