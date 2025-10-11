/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:49:31 by akonstan          #+#    #+#             */
/*   Updated: 2025/09/26 18:49:36 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//A function that returns the quote type of the specified character
t_quote_type	ft_quote_type(int c)
{
	if (c == '\'')
		return (Q_SINGLE);
	if (c == '\"')
		return (Q_DOUBLE);
	return(Q_NONE);
}

//A function that returns the next quote of the specified type
char	*ft_get_next_quote(char *s, t_quote_type type)
{
	if (!s)
	while (*s && (ft_quote_type(*s) != type))
		s++;
	if (!s)
		return (NULL);
	return (s);
}

//A function that returns the first quote to remove (any quote)
char	*ft_get_first_quote(char *s)
{
	if (!s)
		return (NULL);
	while (*s && (*s != '\'' || *s != '\"'))
		s++;
	return (s);
}

//We need a function to remove any quotes that are still in the
//command argument
//We need to pass the address of the target
int	ft_remove_quotes(char **s, t_error err)
{
	char	*ref;
	int		in_squote;
	int		in_dquote;

	if (!s || !*s)
		return (err->remove_quotes = 1);
	ref = *s;
	in_squote = 0;
	in_dquote = 0;
	while (*ref)
	{
		while (*ref && (*ref != '\'' || *ref != '\"'))
			ref++;
		if (*ref == '\'')
		{
			while (*ref && *ref)
		}
	}
}

//A function that removes the given character from the string
//Returns a pointer to the following character
//We pass the address of the string and the address of the char
//to remove
char	*ft_remove_char(char **s, char *c)
{
	char	*ref;
	char	*new;

	if (!s || !*s)
		return (NULL);
	ref = *s;
	new = ft_strjoin(ft_substr(ref, 0 , c - ref), ft_substr(ref, c - ref + 1, ft_strlen(c)));
	
	
}

//We need a function to set the argv for the executor to runs