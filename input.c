/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:47:19 by imellali          #+#    #+#             */
/*   Updated: 2025/01/27 18:08:00 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	**ft_helper(int argc, char **argv)
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
		nums[j] = argv[j + 1];
		j++;
	}
	nums[count] = NULL;
	return (nums);
}

char	**ft_parsing(int argc, char **argv)
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
    return nums;
}

int	ft_dupchek(char **numbers)
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

int	ft_intcheck(char **numbers)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (numbers[i])
	{
		s = numbers[i];
		j = 0;
		if (s[j] == '-') 
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

char	**ft_check(int argc, char **argv)
{
	char **nums;

	nums = ft_parsing(argc, argv);
	if ((ft_dupcheck(nums)) < 0 && (ft_intcheck(nums)) < 0)
	{
		// store it in a linked list
	}
}
