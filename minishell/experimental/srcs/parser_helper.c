/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:51:30 by akonstan          #+#    #+#             */
/*   Updated: 2025/09/28 15:51:36 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//In every case we pass the **token is because we will alter the head
//or/and the values inside the token chain (token list)
//
//A function that counts the amount of tokens a pipe has
size_t	ft_pipelen(t_token *chain)
{
	size_t	token_amount;

	if (!chain)
		return (0);
	token_amount = 0;
	while (chain->type != T_PIPE_OP && chain->type != T_END)
	{
		token_amount++;
		chain = chain->next;
	}
	return (token_amount);
}

//Helper function to extract the command chain from the token chain
t_token	*ft_get_cmd_chain(t_token **chain)
{
	t_token	*temp;
	t_token	*cmd_chain;

	if (!chain)
		return (NULL);
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
	return (cmd_chain);
}

//A function that returns a pointer to the last pipe in the pipeline
t_pipe	*ft_get_last_pipe(t_pipe *pipeline)
{
	if (!pipeline)
		return (NULL);
	while (pipeline->next != NULL)
		pipeline = pipeline->next;
	return (pipeline);
}

//A function that initializes a pipe
t_pipe	*ft_new_pipe(t_token **chain)
{
	t_pipe	*pipe;

	if (!chain)
		return (NULL);
	pipe = ft_calloc(1, sizeof(t_pipe));
	if (!pipe)
		return (NULL);
	pipe->command->cmd_chain = ft_get_cmd_chain(chain);
	pipe->cmd_amount = ft_chainlen(pipe->command->cmd_chain);
	pipe->next = NULL;
	return (pipe);
}

//A function that adds a new pipe to the pipeline
void	ft_add_pipe(t_pipe **pipeline, t_token **chain)
{
	if (!pipeline)
		return ;
	if (!(*pipeline))
		*pipeline = ft_new_pipe(chain);
	else
		(ft_get_last_pipe(*pipeline))->next = ft_new_pipe(chain);
}
