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

//A functions that returns the next occurence of stated quote type
char	*ft_get_next_quote(char *string, t_quote_type q_type)
{
	char	*next;

	if  (!string || q_type == Q_NONE)
		return (NULL);
	if (q_type == Q_DOUBLE )
		next = ft_strchr(string, '\"');
	if (q_type == Q_SINGLE)
		next = ft_strchr(string, '\'');
	if (q_type == Q_BOTH)
	{
		if (ft_strchr(string, '\'') < ft_strchr(string, '\"'))
			next = ft_strchr(string, '\'');
		else
			next = ft_strchr(string, '\"');
	}
	return (next);
}

//A function that exapands the content of a string inside the pipeline
int	ft_expand_string(char **string)
{
}

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
