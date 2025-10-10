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

//Helper function for the ft_expand_dollar function, that returns the amount
//of character the expansion target has
size_t	ft_envlen(char *start, int in_braces, t_error err)
{
	char	*end;

	end = start;
	if (in_braces == 1)
	{
		while (*end && *end != '}' && *end != '\'' && *end != '\"')
			end++;
	}
	else
	{
		while (*end && (*end != ' ' || *end == '}' || *end == '\"'))
			end++;
	}
	if ((!*end && in_braces == 1) || end == start ||
			((in_braces == 1) && (*end == '\'' || *end == '\"')))
	{
		err->env_len = 1;
		return (0);
	}
	err->env_len = 0;
	return ((size_t)(end - start));
}

//A give back the starting address for the expansion
static char	*ft_get_start(char *dollar, int *in_braces, t_error *err)
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
static char	*ft_get_result(char *start, t_shell *shell, int in_braces,)
{
	char	*target;
	char	*result;
	char	*env;

	if (!start || !shell)
		return (NULL);
	env = NULL;
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

//A function that exapands the content of a dollar inside a string
int	ft_expand_dollar(char **dollar, t_shell *shell, t_error *err)
{
	char	*start;
	char	*result;
	char	*temp;
	int		in_braces;

	if (!dollar || !(*dollar))
		return (err->expand_dollar = 1);
	in_braces = 0;
	start = ft_get_start(*dollar, &in_braces, err);
	temp = ft_substr(*dollar, 0, ft_strchr(*dollar, '$') - *dollar);
	result = ft_strjoin(temp , ft_get_result(start, shell, in_braces));
	free(temp);
	free(*dollar);
	*dollar = result;
	return (err->expand_dollar = 0);
}

//A function that returns a pointer to the first $ that can be expanded
char	*ft_get_dollar(char *str, t_error *err)
{
	int		in_squote;
	
	if (!str)
	{
		err->get_dollar = 1;
		return (NULL);
	}
	in_squote = 0;
	while (*str)
	{
		if (*str == '\'')
		{
			if (in_squote == 0)
				in_squote = 1;
			else
				in_squote = 0;
		}
		if (*str == '$' && in_squote == 0)
			return (str);
		else
			str++;
	}
	return (NULL);
}
//A function that expands all $ in  a given string
int	ft_expand_str(char **str, t_shell *shell, t_error *err)
{
	char	*ref;

	if (!str)
		return(err->expand_str = 1);
	ref = *str;
	while (ft_get_dollar(ref, err) != NULL)
		ft_expand_dollar(&ft_get_dollar(ref, err), shell, err);
	return (err->expand_str = 0);
}

//A function that expands all strings in the given redirection chain
int	ft_expand_redir(t_redirect *red_chain, t_shell *shell, t_error *err)
{
	if (!red_chain)
		return (err->expand_redir = 1);
	while (red_chain)
	{
		ft_expand_str(&(red_chain->target), shell, err);
		red_chain = red_chain->next;
	}
	return (err->expand_redir = 0);
}

//A function that expands all strings in the given command chain
int	ft_expand_cmd(t_token *cmd_chain, t_shell *shell, t_error *err)
{
	if (!cmd_chain)
		return (err->expand_cmd = 1);
	while (cmd_chain)
	{
		
	}
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
	while (pipeline != NULL)
	{
		cmd_chain = pipeline->command->cmd_chain;
		red_chain = pipeline->command->red_chain;
		while ()
	}
}
