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

t_token	*ft_get_cmd_chain(t_token **chain)
{
	t_token	*temp;
	t_token	*cmd_chain;

	if (!chain)
		return(NULL);
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
