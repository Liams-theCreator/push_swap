/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:32:41 by imellali          #+#    #+#             */
/*   Updated: 2025/01/28 18:34:40 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct list_a
{
	int				num;
	struct list_a	*next;
}	t_lista;

// string functions
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);

// input functions
t_lista	*ft_check(int argc, char **argv);

// linked list functions
void	ft_add_to_list(t_lista **head, char **nums);

// error handling functions
void	ft_error(void);
void	free_array(char **array);

#endif
