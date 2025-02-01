/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:50:50 by imellali          #+#    #+#             */
/*   Updated: 2025/02/01 17:13:43 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	// t_lista	*stack_b;

	if (argc <= 1)
		ft_error();
	stack_a = NULL;
	stack_a = ft_parsing(argc, argv);
	
	if ((sorted(stack_a)) == -1)
	{
		print_list(stack_a);
		if (argc == 3)
		{
			sort_two(&stack_a);
			print_list(stack_a);
			free_list(&stack_a);
		}
	}
	return (0);
}
