/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:50:50 by imellali          #+#    #+#             */
/*   Updated: 2025/01/29 16:29:03 by imellali         ###   ########.fr       */
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

static void	free_list(t_lista **head)
{
	t_lista	*temp;

	while (*head)
	{
		temp = *head;
		*head = temp->next;
		free(temp);
	}
	*head = NULL;
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
