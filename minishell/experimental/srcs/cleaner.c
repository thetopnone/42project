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

//A function that clears head token from the chain
static void	ft_clear_head_token(t_token **chain)
{
	t_token	*head;

	if (!chain || !(*chain))
		return ;
	head = (*chain)->next;
	(*chain)->next = NULL;
	if ((*chain)->string)
	{
		free((*chain)->string);
		(*chain)->string = NULL;
	}
	free(*chain);
	(*chain) = head;
}

//A function that clears the specififed token from the chain
void	ft_clear_token(t_token **chain, t_token *token)
{
	t_token	*temp;

	if (!chain || !(*chain) || !token)
		return ;
	temp = NULL;
	if (token == (*chain))
	{
		ft_clear_head_token(chain);
		return ;
	}
	while ((*chain)->next != token && (*chain))
		(*chain) = (*chain)->next;
	if (*chain == NULL || (*chain)->type == T_END)
		return ;
	temp = (*chain)->next->next;
	if ((*chain)->next->string)
	{
		free((*chain)->next->string);
		(*chain)->next->string = NULL;
	}
	free((*chain)->next);
	(*chain)->next = temp;
}
