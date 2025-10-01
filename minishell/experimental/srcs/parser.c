/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:49:54 by akonstan          #+#    #+#             */
/*   Updated: 2025/09/26 18:49:55 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//In every case we pass the **token is because we will alter the head
//or/and the values inside the token chain (token list)
//
//A functions that "feeds" the tokens to the pipe
//Triple pointer so we pass the token array by value so we will already have
//it moving while inserting (will not need to parse the whole array every time)
void	ft_cmd_chain(t_token **dest, t_token ***src)
{
	if (!dest || !src)
		return (NULL);
	dest = *src;
	while ((*src)->type != T_PIPE_OP && (*src)->type != T_END)
		&src = (**src)->next;
}

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

//A function that initializes a pipe
t_pipe	*ft_new_pipe(t_token **chain)
{
	t_pipe	*pipe;
	t_token	*temp;

	if (!chain)
		return (NULL);
	pipe = ft_calloc(1, sizeof(t_pipe));
	temp = NULL;
	if (!pipe)
		return (NULL);
	pipe->command->cmd_chain = ft_get_cmd_chain(chain);
	pipe->cmd_amount = ft_chainlen(pipe->command->cmd_chain);
	return (pipe);
}

//Main parsing function
t_pipe	*parser(t_token **chain)
{
	while ((*token)->type != T_END)
	{
		(*token) = (*token)->next;
	}
}
