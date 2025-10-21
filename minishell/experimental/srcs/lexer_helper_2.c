/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mini.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:31:19 by akonstan          #+#    #+#             */
/*   Updated: 2025/10/02 17:54:00 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_inquote(char c, int *s_quote, int *d_quote);

static void	ft_freearr(char **arr, size_t index)
{
	while (index > 0)
	{
		index--;
		free(arr[index]);
	}
	free(arr);
}

static void	ft_inquote(char c, int *s_quote, int *d_quote)
{
	if (c == '\'')
	{
		if (*s_quote)
			*s_quote = 0;
		else
			*s_quote = 1;
	}
	else if (c == '"')
	{
		if (*d_quote)
			*d_quote = 0;
		else
			*d_quote = 1;
	}
	else
		return ;
}

static size_t	ft_word_amount(char const *s, char c)
{
	size_t	words;
	int		in_word;
	int		in_squote;
	int		in_dquote;

	words = 0;
	in_word = 0;
	in_squote = 0;
	in_dquote = 0;
	while (*s)
	{
		if (*s == '"' || *s == '\'')
			ft_inquote(*s, &in_squote, &in_dquote);
		else if (*s == c && !(in_squote || in_dquote))
			in_word = 0;
		else if (*s != c && in_word == 0)
		{
			in_word = 1;
			words++;
			if (!in_squote && *s == '"')
				ft_inquote(*s, &in_squote, &in_dquote);
			else if (!in_dquote && *s == '\'')
				ft_inquote(*s, &in_squote, &in_dquote);
		}
		s++;
	}
	if (in_squote || in_dquote)
	{
		//PROPER ERROR HANDLING HERE
		printf("ERROR\n");
		exit(1);
	}
	return (words);
}
/**/
static void	ft_dquote_scope(char const **s)
{
	(*s)++;
	while (**s && **s != '"')
		(*s)++;
}

static void	ft_squote_scope(char const **s)
{
	(*s)++;
	while (**s && **s != '\'')
		(*s)++;
}

//This function handles the quotes in write word
static int  ft_handle_quotes(char **s)
{
	if (!s || !*s)
		return (-1);
	if (**s == '"')
		ft_dquote_scope(s);
	else if (**s == '\'')
		ft_squote_scope(s);
	return (0);
}

//This function handles the redirections in write word
static int	ft_handle_redir(char **s)
{
	if (!s || !*s)
		return (-1);
	if (**s == '>')
	{
		while (**s == '>')
			(*s)++;
	}
	else if (**s == '<')
	{
		while (**s == '<')
			(*s)++;
	}
	return (0);
}

//Added redirection case where it will always treat redirections
//and the target as different tokens
//Also fixed a small bug for starting or trailing spaces
static char	*ft_write_word(char const **s, char c)
{
	char const	*start;
	char		*word;

	while (**s == c)
		(*s)++;
	start = *s;
	while (**s)
	{
		if (**s == '"' || **s == '\'')
			ft_handle_quotes(s);
		else if (**s == '>' || **s == '<')
		{
			ft_handle_redir(s);
			break;
		}
		else if (**s == c)
			break ;
		(*s)++;
	}
	word = malloc((*s - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, *s - start + 1);
	return (word);
}

static int	ft_split_logic(char **str_arr, char const *s, char c)
{
	size_t		index;
	int	quote;

	index = 0;
	quote = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			str_arr[index] = ft_write_word(&s, c);
			if (!str_arr[index])
			{
				ft_freearr(str_arr, index);
				return (0);
			}
			index++;
		}
	}
	str_arr[index] = NULL;
	return (1);
}

char	**ft_split_mini(char const *s, char c)
{
	char		**str_arr;

	if (!s || *s == '\0')
	{
		str_arr = malloc(1 * sizeof(char *));
		str_arr[0] = NULL;
		return (str_arr);
	}
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

/*int	main(int argc, char *argv[])
{
	char	**array;
	int	i;

	array = ft_split_mini(argv[1], ' ');
	i = -1;
	while (array[++i])
		printf("ARRAY[%i]: %s\n",i , array[i]);
}*/
