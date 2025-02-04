/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:46:37 by imellali          #+#    #+#             */
/*   Updated: 2025/02/03 16:24:58 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	list_len(t_lista *h)
{
	int	len;

	len = 0;
	while (h)
	{
		h = h->next;
		len++;
	}
	return (len);
}

t_lista	*ft_create_node(t_lista **head, int num)
{
	t_lista	*node;
	t_lista	*h;

	h = *head;
	node = malloc(sizeof(t_lista));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = h;
	*head = node;
	return (node);
}

void	ft_add_to_list(t_lista **head, char **array, int num)
{
	t_lista	*current;

	current = *head;
	while (current)
	{
		if (current->num == num)
			exiting(array, head);
		current = current->next;
	}
	ft_create_node(head, num);
}
