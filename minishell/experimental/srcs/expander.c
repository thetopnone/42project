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

//Helper function for the ft_expand_dollar function, that returns the amount
//of character the expansion target has
size_t	ft_envlen(char *start, int in_braces, t_error err)
{
	char	*end;

	end = start;
	if (in_braces == 1)
	{
		while (*end && *end != '}')
			end++;
	}
	else
	{
		while (*end && (*end != ' ' || *end == '}'))
			end++;
	}
	if ((!*end && in_braces == 1) || end == start)
	{
		err->env_len = 1;
		return (0);
	}
	err->env_len = 0;
	return ((size_t)(end - start));
}

//A give back the starting address for the expansion
char	*ft_get_start(char *dollar, int *in_braces, t_error *err)
{
	char	*start;

	start = dollar + 1;
	if (start == '{')
	{
		*in_braces = 1;
		start++;
	}
	return (start);
}

//A function that sets the result char * of the expanding the $ sign
char	*ft_get_result(char *start, t_shell *shell, int in_braces,)
{
	char	*target;
	char	*result;

	if (!start || !shell)
		return (NULL);
	if (*start == '?')
	{
		target = ft_itoa(shell->last_exit);
		result = ft_strjoin(target, &(start + 1));
	}
	else
	{
		target = ft_calloc(ft_envlen(start, in_braces, err) + 1, sizeof(char));
		ft_strlcpy(target, start, ft_envlen(start, in_braces, err) + 1);
		env = getenv(target);
		result = ft_strjoin(env, &start[ft_envlen(start, in_braces, err)]);
		free(env);
	}
	return (result);
}

//A function that exapands the content of a dollar inside the pipeline
char	*ft_expand_dollar(char **dollar, t_shell *shell, t_error *err)
{
	char	*start;
	char	*env;
	char	*result;
	char	*temp;
	int		in_braces;

	if (!dollar || !(*dollar))
		return (err->expand_dollar = 1);
	in_braces = 0;
	start = ft_get_start(*dollar, &in_braces, err);
	temp = ft_substr(*dollar, 0, ft_strchr(*dollar, '$') - *dollar);
	result = ft_strjoin(temp , ft_get_result(start, shell, in_braces));
	free(start);
	free(temp);
	free(*dollar);
	*dollar = result;
	return (err->expand_dollar = 0);
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
	cmd_chain = pipeline;
}
