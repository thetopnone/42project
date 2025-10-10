/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:07:54 by akonstan          #+#    #+#             */
/*   Updated: 2025/10/09 20:07:57 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//A functions that returns the next occurence of stated quote type
char	*ft_get_next_quote(char *string, t_quote_type q_type)
{
	char	*next;

	if (!string || q_type == Q_NONE)
		return (NULL);
	if (q_type == Q_DOUBLE)
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
