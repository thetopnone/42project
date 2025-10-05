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

//A function that clears the first redirection on the red_chain
void	ft_clear_head_redir(t_token *red_chain)
{
	t_redirect	*head
	
	if (!red_chain)
		return ;
	head = red_chain->next;
	red_chain->next = NULL;
	if (red_chain->target)
	{
		free(red_chain->target);
		red_chain->target = NULL;
	}
	free(red_chain);
	red_chain = head;
}