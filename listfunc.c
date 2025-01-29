/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:46:37 by imellali          #+#    #+#             */
/*   Updated: 2025/01/29 16:31:27 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_lista	*ft_create_node(t_lista **head, int num)
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

void	ft_add_to_list(t_lista **head, int num)
{
	t_lista	*current;

	current = *head;
	while (current)
	{
		if (current->num == num)
			ft_error();
		current = current->next;
	}
	ft_create_node(head, num);
}
