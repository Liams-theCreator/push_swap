/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:08:13 by imellali          #+#    #+#             */
/*   Updated: 2025/01/21 13:45:18 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct list_t
{
	int n;
	struct list_t *next;
}	lista;

size_t print_listint(lista *h)
{
	size_t nodes = 0;
	
	while (h != NULL)
	{
		printf("  [ %d ]  ", h->n);
		h = h->next;
		nodes++;
	}
	printf("\n");
	return nodes;
}

size_t listint_len(lista *h)
{
	size_t len = 0;

	while (h)
	{
		h = h->next;
		len++;
	}
	return len;
}

lista *add_nodeint(lista **head, int n)
{
	lista *node;
	lista *h = *head;

	node = malloc(sizeof(lista));
	if (!node)
		return NULL;
	node->n = n;
	node->next = h;
	*head = node;

	return node;
}

lista *add_nodeint_back(lista **head, int n)
{
	lista *node;
	lista *temp = *head;

	node = malloc(sizeof(lista));
	if (!node)
		return NULL;
	node->n = n;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return node;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;

	return node;
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

int main(void)
{
	lista *head;
	
	head = NULL;
	add_nodeint(&head, 1);
	add_nodeint(&head, 2);
	add_nodeint(&head, 3);
	
	print_listint(head);
	printf("--> %ld Nodes\n", listint_len(head));

	free_list(&head);
	return 0;
}
