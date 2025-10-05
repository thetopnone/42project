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

//A function that clears head token from the chain
int	ft_clear_head_token(t_token **chain)
{
	t_token	*head;

	if (!chain || !(*chain))
		return (1);
	head = (*chain)->next;
	(*chain)->next = NULL;
	ft_clean_string(&((*chain)->string));
	free(*chain);
	*chain = head;
	return (0);
}

//A function that clears last token
int	ft_clear_last_token(t_token  **chain)
{
	t_token	*cur;

	if (!chain || !(*chain))
		return (1);
	cur = *chain;
	if (cur->next == NULL || cur->type == T_END)
	{
		ft_clean_string(&(cur->string));
		free(cur);
		cur = NULL;
		return (0);
	}
}
