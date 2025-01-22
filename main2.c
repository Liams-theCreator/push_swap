/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:08:13 by imellali          #+#    #+#             */
/*   Updated: 2025/01/22 20:46:25 by imellali         ###   ########.fr       */
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

int pop_listint(lista **head)
{
	int temp;
	lista *h;

	if (*head == NULL)
		return 0;
	
	h = *head;
	temp = (*head)->n;
	*head = (*head)->next;
	
	free(h);
	h = NULL;

	return (temp);
}

lista *get_nodeint_at_index(lista *head, unsigned int index)
{
	size_t len = listint_len(head);
	unsigned int i = 0;
	
	while (i < len)
	{
		if (i == index)
			return head;
		head = head->next;
		i++;
	}
	return NULL;
}

int sum_listint(lista *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return sum;
}

lista *insert_nodeint_at_index(lista **head, unsigned int index, int n)
{
	lista *temp = *head;
	lista *node;
	unsigned int i = 0;

	node = malloc(sizeof(lista));
	if (!node)
		return NULL;
	node->n = n;

	if (index == 0)
	{
		node->next = *head;
		*head = node;
		return node;
	}
	
	while (temp != NULL)
	{
		if (i + 1 == index)
		{
			node->next = temp->next;
			temp->next = node;
			return node;
		}
		i++;
		temp = temp->next;
	}
	free(node);
	return NULL;
}

int delete_nodeint_at_index(lista **head, unsigned int index)
{
	lista *temp = *head;
	lista *target;
	unsigned int i = 0;

	if (!head || *head == NULL)
		return -1;

	if (index == 0)
	{
		target = *head;
		*head = (*head)->next;
		free(target);
		return 1;
	}

	while (i < index && temp != NULL)
	{
		if (i + 1 == index)
		{
			target = temp->next;
			temp->next = temp->next->next;
			free(target);
			return 1;
		}
		i++;
		temp = temp->next;
	}
	return -1;
}

int main(void)
{
    lista *head;

    head = NULL;
    
	add_nodeint_back(&head, 0);
    add_nodeint_back(&head, 1);
    add_nodeint_back(&head, 2);
    add_nodeint_back(&head, 3);
    add_nodeint_back(&head, 4);
    add_nodeint_back(&head, 98);
    add_nodeint_back(&head, 402);
    add_nodeint_back(&head, 1024);
    
	print_listint(head);
    printf("-----------------\n");
    
	insert_nodeint_at_index(&head, 5, 4096);
    delete_nodeint_at_index(&head, 8);
	print_listint(head);
    
	free_list(&head);
    return (0);
}

