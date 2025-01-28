/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:47:19 by imellali          #+#    #+#             */
/*   Updated: 2025/01/28 18:34:07 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static char	**ft_helper(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**nums;

	i = 1;
	j = 0;
	count = 0;
	while (i < argc)
	{
		count++;
		i++;
	}
	nums = malloc(sizeof(char *) * (count + 1));
	if (!nums)
		return (NULL);
	while (j < count)
	{
		nums[j] = ft_strdup(argv[j + 1]);
		j++;
	}
	nums[count] = NULL;
	return (nums);
}

static char	**ft_parsing(int argc, char **argv)
{
	char	**nums;

	if (argc <= 1)
		return (NULL);
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (!nums)
			return (NULL);
	}
	else
	{
		nums = ft_helper(argc, argv);
		if (!nums)
			return (NULL);
	}
	return (nums);
}

static int	ft_dupcheck(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_strcmp(numbers[i], numbers[j]) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_intcheck(char **numbers)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (numbers[i])
	{
		s = numbers[i];
		j = 0;
		if (s[j] == '-' || s[j] == '+')
			j++;
		while (s[j])
		{
			if (s[j] < '0' || s[j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

t_lista	*ft_check(int argc, char **argv)
{
	char	**nums;
	t_lista	*head;

	head = NULL;
	nums = ft_parsing(argc, argv);
	if (!nums)
		return (NULL);
	if ((ft_dupcheck(nums)) == 0 && (ft_intcheck(nums)) == 0)
	{
		ft_add_to_list(&head, nums);
		free_array(nums);
		return (head);
	}
	free_array(nums);
	ft_error();
	return (NULL);
}
