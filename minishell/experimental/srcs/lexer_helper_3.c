/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:31:19 by akonstan          #+#    #+#             */
/*   Updated: 2025/10/22 18:17:28 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_inquote(char c, int *s_quote, int *d_quote, char **s)
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
}

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
static void	ft_handle_quotes(const char **s)
{
	if (!s || !*s)
		return ;
	if (**s == '"')
		ft_dquote_scope(s);
	else if (**s == '\'')
		ft_squote_scope(s);
}

//This function handles the redirections in write word
static void	ft_handle_redir(const char **s)
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
		while (**s == '>')
			(*s)++;
	}
}
