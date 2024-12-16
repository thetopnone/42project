/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:31:22 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/16 23:29:23 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_freearr(char **arr, size_t index)
{
	while (index > 0)
	{
		index--;
		free(arr[index]);
	}
	free(arr);
}

static size_t	ft_word_amount(char const *s, char c)
{
	size_t	words;
	int		in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			words++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (words);
}

static char	*ft_write_word(char const *s, char c)
{
	char const	*start;
	char		*word;

	start = s;
	while (*s && *s != c)
		s++;
	word = malloc((s - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, s - start + 1);
	return (word);
}

static int	ft_split_logic(char **str_arr, char const *s, char c)
{
	size_t		index;

	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			str_arr[index] = ft_write_word(s, c);
			if (!str_arr[index])
			{
				ft_freearr(str_arr, index);
				return (0);
			}
			index++;
			while (*s && *s != c)
				s++;
		}
	}
	str_arr[index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**str_arr;

	if (!s || *s == '\0')
		return (NULL);
	str_arr = malloc((ft_word_amount(s, c) + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	if (!ft_split_logic(str_arr, s, c))
	{
		free(str_arr);
		return (NULL);
	}
	return (str_arr);
}
