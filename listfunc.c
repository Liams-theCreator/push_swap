/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:46:37 by imellali          #+#    #+#             */
/*   Updated: 2025/01/28 18:35:47 by imellali         ###   ########.fr       */
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

void	ft_add_to_list(t_lista **head, char **nums)
{
	int		i;

	i = 0;
	while (nums[i])
	{
		ft_create_node(head, ft_atoi(nums[i]));
		i++;
	}
}
