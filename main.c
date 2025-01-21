/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:00:34 by imellali          #+#    #+#             */
/*   Updated: 2025/01/19 13:24:39 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct list_t
{
	char *str;
	int num;
	size_t len;
	struct list_t *next;
} lista;

void print_list(lista *node)
{
	while (node)
	{
		printf("[%ld] %d\n", node->len, node->num);
		node = node->next;
	}
}

void print_len(lista *node)
{
	size_t len = 0;

	while (node)
	{
		len++;
		node = node->next;
	}
	printf("--> Elements : %ld\n", len);
}

lista *add_node(lista **head, char *s)
{
	lista *node;

	node = malloc(sizeof(lista));
	if (!node)
		return (NULL);

	node->str = strdup(s);
	if (node->str == NULL)
		return NULL;
	node->len = strlen(node->str);
	node->next = *head;
	*head = node;

	return node;
}

lista *add_back_node(lista **head, char *s)
{
	lista *node;
	lista *temp = *head;

	node = malloc(sizeof(lista));
	if (!node)
		return (NULL);
	
	node->str = strdup(s);
	if (!(node->str))
		return NULL;
	node->len = strlen(s);
	node->next = NULL;

	if (*head == NULL)
		*head = node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
	return node;
}

void free_list(lista **head)
{
	lista *temp = *head;
	lista *newnode;

	while (temp != NULL)
	{
		newnode = temp->next;
		free(temp->str);
		free(temp);
		temp = newnode;
	}
	*head = NULL;
}

lista *add_node_back(lista **h, int n)
{
	lista *node;
	lista *head = *h;

	node = malloc(sizeof(lista));
	if (!node)
		return NULL;

	node->num = n;
	node->str = strdup("");
	if (!(node->str))
		return NULL;
	node->next = NULL;

	if (*h == NULL)
		*h = node;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = node;
	}
	return node;
}

int main(void)
{
	lista *head = NULL;

	add_node_back(&head, 1);
    add_node_back(&head, 2);
    add_node_back(&head, 3);
    add_node_back(&head, 4);
    add_node_back(&head, 5);
    add_node_back(&head, 6);

	print_list(head);
	print_len(head);
	free_list(&head);

	return (0);
}
