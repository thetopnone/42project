/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:37:10 by akonstan          #+#    #+#             */
/*   Updated: 2025/10/01 18:37:11 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//A functon that returns the redirection type (checking +1 len in case of >>>)
static t_redir_type	ft_get_redir_type(char *string)
{
	if (ft_strncmp(string, ">", 2))
		return (RE_OUT);
	if (ft_strncmp(string, "<", 2))
		return (RE_IN);
	if (ft_strncmp(string, ">>", 3))
		return (RE_APPEND);
	if (ft_strncmp(string, "<<", 3))
		return (RE_HEREDOC);
	return (RE_NONE);
}

//A function that extracts the redirections from the cmd_chain
t_redirect	*ft_get_red_chain(t_token *cmd_chain)
{
	t_redirect		*red_chain;
	t_redir_type	red_type;
	t_quote_type	q_type;
	char			*target;

	if (!cmd_chain)
		return (NULL);
	red_chain = NULL;
	target = NULL;
	red_type = 0;
	q_type = 0;
	while (cmd_chain->type != T_END)
	{
		if (cmd_chain->type == T_REDIR)
		{
			red_type = ft_get_redir_type(cmd_chain->string);
			target = cmd_chain->next->string;
			q_type = cmd_chain->next->q_type;
			ft_add_redir(&red_chain, ft_new_redir(red_type, target, q_type));
			cmd_chain = cmd_chain->next;
		}
		cmd_chain = cmd_chain->next;
	}
}

//I need a function to purify the cmd_chain from redirections and the filenames
int	ft_purify_cmd_chain(t_token **cmd_chain, t_error *err)
{
	t_token	**target;

	if (!cmd_chain)
		return (err->purify_cmd_chain = 1);
	if (!(*cmd_chain))
	target = cmd_chain;
	while ((*target)->type != T_END)
	{
		if ((*target)->type == T_REDIR)
		{
			if (!(*target)->next)
				return (err->purify_cmd_chain = 1);
			temp = (*target)->next->next;
			ft_del_token(cmd_chain, (*target)->next);
			ft_del_token(cmd_chain, *target);
		}
		*target = temp;
	}
	return (err->purify_cmd_chain = 0);
}

//Helper function to extract the command chain from the token chain
t_token	*ft_get_cmd_chain(t_token **chain, t_error *err)
{
	t_token	*temp;
	t_token	*cmd_chain;

	if (!chain)
	{
		err->get_cmd_chain = 1;
		return (NULL);
	}
	temp = NULL;
	cmd_chain = *chain;
	while ((*chain)->type != T_END)
	{
		*chain = (*chain)->next;
		if ((*chain)->type == T_PIPE_OP)
		{
			temp = (*chain)->next;
			(*chain)->type = T_END;
			(*chain)->next = NULL;
			*chain = temp;
			break ;
		}
	}
	err->get_cmd_chain = 0;
	return (cmd_chain);
}
