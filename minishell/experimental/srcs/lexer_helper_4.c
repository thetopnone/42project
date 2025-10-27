/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:18:31 by mstawski          #+#    #+#             */
/*   Updated: 2025/10/22 18:20:40 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_handle_quo_red_wa(char **s, t_word_amount *state)
{
	if (!s || *s)
		return ;
	if (**s == '"' || **s == '\'')
		ft_inquote(**s, &state->in_squote, &state->in_dquote);
	else
	{
		state->words++;
		state->in_word = 0;
		ft_handle_redir(s);
	}
}

int	ft_handle_quo_red_ww(char **s, int *redir, int *i)
{
	if (**s == '"' || **s == '\'')
	{
		ft_printf("HERE\n");
		ft_handle_quotes(s);
	}
	else
	{
		ft_printf("HERE\n");
		if (!*redir && !*i)
		{
			ft_handle_redir(s);
			*redir = 1;
		}
		else
			*redir = 0;
		return (1);
	}
	ft_printf("HERE\n");
	return (0);
}
