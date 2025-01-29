/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:50:50 by imellali          #+#    #+#             */
/*   Updated: 2025/01/29 19:08:41 by imellali         ###   ########.fr       */
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
		printf("  [ %d ]  ", h->num);
		h = h->next;
		nodes++;
	}
	printf("\n");
	return (nodes);
}

int	main(int argc, char **argv)
{
	t_lista	*head;

	if (argc <= 1)
		ft_error();
	head = ft_parsing(argc, argv);
	print_list(head);
	free_list(&head);
	return (0);
}
