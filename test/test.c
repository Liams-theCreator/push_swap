/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:46:52 by imellali          #+#    #+#             */
/*   Updated: 2025/01/24 18:47:57 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/**
 * _strchr -  locates a character in a string
 * @s: pointer to string
 * @c: pointer to character
 * Return: if c found return occurence if its not return NULL
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}
	if (s[i] == c)
		return (&s[i]);

	return (NULL);
}

/**
 * _strtok - Tokenize a string using specified delimiters.
 * @str: The string to tokenize.
 * @dahawmitr: The delimiters used for tokenization.
 * Return: pointer to the next token or NULL if no more tokens are found.
 */

char *_strtok(char *str, char *dahawmitr)
{
	static char *buffer;
	char *token, *agadir;

	if (str != NULL)
		buffer = str;
	if (buffer == NULL)
		return (NULL);
	while (*buffer != '\0' && _strchr(dahawmitr, *buffer) != NULL)
		buffer++;
	token = buffer;
	agadir = buffer;
	while (*agadir != '\0')
	{
		if (_strchr(dahawmitr, *agadir) != NULL)
		{
			*agadir = '\0';
			buffer = agadir + 1;
			return (token);
		}
		agadir++;
	}
	buffer = NULL;
	return (token);
}


int main()
{
	char s1[] = "Liams the Creator";
	char dh[] = " ";
	char *ss;

	ss = _strtok(s1, dh);

	while (ss != NULL)
	{
		printf("%s\n", ss);
		ss = _strtok(NULL, dh);
	}
	return 0;
}
