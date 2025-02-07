#include "pushswap.h"

int	find_max(t_lista *stack_a)
{
	int		max_num;
	int		its_index;
	int		counter;
	t_lista	*head;

	max_num = stack_a->num;
	its_index = 0;
	counter = 0;
	head = stack_a;
	while (head)
	{
		if (head->num > max_num)
		{
			max_num = head->num;
			its_index = counter;
		}
		counter++;
		head = head->next;
	}
	return (its_index);
}

int	find_min(t_lista *stack_a)
{
	int		min_num;
	int		its_index;
	int		counter;
	t_lista	*head;

	min_num = stack_a->num;
	its_index = 0;
	counter = 0;
	head = stack_a;
	while (head)
	{
		if (head->num < min_num)
		{
			min_num = head->num;
			its_index = counter;
		}
		counter++;
		head = head->next;
	}
	return (its_index);
}
