/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:23:36 by akonstan          #+#    #+#             */
/*   Updated: 2025/10/07 16:23:37 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_expand_string
//This function will get inside the pipeline and expand on all the variables 
//that need to be expanded
//It only needs to handle $word , $? ,${word}line 
int	ft_expander(t_pipe *pipeline, t_error *err)
{
	t_token		*cmd_chain;
	t_redirect	*red_chain;

	if (!pipeline)
		return (err->expander = 1);
	cmd_chain = pipeline
}
