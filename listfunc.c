/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:46:37 by imellali          #+#    #+#             */
/*   Updated: 2025/01/28 15:40:55 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

lista	*ft_create_node(lista **head, int num)
{
	lista	*node;
	lista	*h;

	h = *head;
	node = malloc(sizeof(lista));
	if (!node)
		return (NULL);

	node->num = num;
	node->next = h;
	*head = node;

	return (node);
}

void	ft_add_to_list(lista **head, char **nums)
{
	int		i;
	int		number;

	i = 0;
	while (nums[i])
	{
		number = ft_atoi(nums[i]);
		ft_create_node(head, number);
		i++;
	}
}
