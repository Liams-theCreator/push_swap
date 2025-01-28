/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:50:50 by imellali          #+#    #+#             */
/*   Updated: 2025/01/28 16:30:45 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

size_t print_list(lista *h)
{
	size_t nodes = 0;
	
	while (h != NULL)
	{
		printf("  [ %d ]  ", h->num);
		h = h->next;
		nodes++;
	}
	printf("\n");
	return nodes;
}

void free_list(lista **head)
{
	lista *temp;

	while (*head)
	{
		temp = *head;
		*head = temp->next;
		free(temp);
	}
	*head = NULL;
}

int main(int argc, char **argv)
{
	lista *head;

	if (argc <= 1)
	{
		ft_error();
		return -1;
	}
	head = ft_check(argc, argv);
	if (head != NULL)
	{
		print_list(head);
		free_list(&head);
	}
	return (0);
}
