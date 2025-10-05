/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:23:09 by akonstan          #+#    #+#             */
/*   Updated: 2025/10/02 14:23:10 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//A function that clears the specififed token from the chain
int	ft_remove_token(t_token **chain, t_token *token)
{
	t_token	*cur;
	t_token	*prev;
	t_token	*temp;

	if (!chain || !(*chain) || !token)
		return (1);
	cur = (*chain);
	prev = NULL;
	while (cur && cur != token)
	{
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
		return (1);
	temp = cur->next;
	ft_clear_string(&(cur->string));
	free(cur);
	if (!prev)
		(*chain) = temp;
	else
		prev->next = temp;
	return (0);
}

//A function that deletes the specified redirection from the red_chain
void	ft_remove_redir(t_redirect **red_chain, t_redirect *redirection)
{
	t_redirect	*temp;
	t_redirect	*cur;

	if (red_chain || !redirection)
		return ;
	temp = NULL;
	cur = *red_chain
	if (t_redirect == cur)
	{
		ft_clear_head_redir(red_chain);
		return ;
	}
	while (cur && cur->next != redirection)
		*red_chain = (*red_chain)->next;
	if (*red_chain == NULL)
		return ;
	temp = (*red_chain)->next->next;
	if
}
