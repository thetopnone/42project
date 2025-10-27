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

void	ft_inquote(char c, int *s_quote, int *d_quote)
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

void	ft_dquote_scope(char **s)
{
	(*s)++;
	while (**s && **s != '"')
		(*s)++;
}

void	ft_squote_scope(char **s)
{
	(*s)++;
	while (**s && **s != '\'')
		(*s)++;
}

//This function handles the quotes in write word
void	ft_handle_quotes(char **s)
{
	if (!s || !*s)
		return ;
	if (**s == '"')
	{
		ft_dquote_scope(s);
	}
	else if (**s == '\'')
		ft_squote_scope(s);
}

//This function handles the redirections in write word
void	ft_handle_redir(char **s)
{
	if (!s || !*s)
		return ;
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
