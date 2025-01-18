/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:00:34 by imellali          #+#    #+#             */
/*   Updated: 2025/01/18 17:17:14 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct list_t
{
	char *str;
	size_t len;
	struct list_t *next;
} lista;

void print_list(lista *node)
{
	while (node)
	{
		printf("[%ld] %s\n", node->len, node->str);
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

void free_list(lista *head)
{
	lista *temp = head;
	lista *newnode;

	while (temp != NULL)
	{
		newnode = temp->next;
		free(temp->str);
		free(temp);
		temp = newnode;
	}
	temp = NULL;
}

int main(void)
{
	lista *head = NULL;
	
	add_node(&head, "FIRST");
    add_node(&head, "SECOND");
    add_node(&head, "THIRD");
    add_node(&head, "FOURTH");
    add_node(&head, "FIFTH");
    add_node(&head, "SIXTH");

	print_list(head);
	print_len(head);
	free_list(head);
    return (0);
}
