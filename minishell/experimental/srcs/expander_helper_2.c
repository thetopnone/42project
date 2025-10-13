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
static t_quote_type	ft_quote_type(int c)
{
	if (c == '\'')
		return (Q_SINGLE);
	if (c == '\"')
		return (Q_DOUBLE);
	return(Q_NONE);
}

//A function that returns the next quote of the specified type
static char	*ft_get_next_quote(char *s, t_quote_type type)
{
	if (!s || type == T_NONE)
		return (NULL);
	while (*s && (ft_quote_type(*s) != type))
		s++;
	if (!s)
		return (NULL);
	return (s);
}

//A function that returns the first quote to remove (any quote)
static char	*ft_get_first_quote(char *s)
{
	if (!s)
		return (NULL);
	while (*s && (*s != '\'' || *s != '\"'))
		s++;
	return (s);
}

//A function that removes the given character from the string
//Returns a pointer to the following character
//We pass the address of the string and the address of the char
//to remove
//DRAW THIS ON BOARD SO YOU MAKE SURE IT RETURS THE RIGHT SPOT!!!
//Checked with the board, all looks good !
char	*ft_rmchar(char **s, char *c)
{
	char	*ref;
	char	*new;
	size_t	index;

	if (!s || !*s || !c)
		return (NULL);
	ref = *s;
	index = c - ref;
	new = ft_strjoin(ft_substr(ref, 0 , index), ft_substr(ref, index + 1, ft_strlen(c)));
	free(*s);
	*s = new;
	return (*s + index);
}

//We need a function to remove any quotes that are still in the
//command argument
//We need to pass the address of the target
int	ft_rmquotes(char **s, t_error *err)
{
	char	*ref;
	char	*o_quote;
	char	*c_quote;

	if (!s || !*s)
		return (err->rmquotes = 1);
	ref = *s;
	while (*ref)
	{
		o_quote = ft_get_first_quote(ref);
		c_quote = ft_get_next_quote(ref, ft_quote_type(*o_quote));
		ref = ft_rmchar(s, o_quote);
		ref = ft_rmchar(s, c_quote);
	}
	return (err->rmquotes = 0);
}
