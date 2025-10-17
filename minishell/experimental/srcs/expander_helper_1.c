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

//Helper function for the ft_expand_dollar function, that returns the amount
//of character the expansion target has
static size_t	ft_varlen(char *start, int in_braces, t_error *err)
{
	char	*end;

	end = start;
	while (*end && ft_isenvchar(*end) == 1)
		end++;
	if ((!*end && in_braces == 1) || end == start ||
			((in_braces == 1) && ft_isenvchar(*end) == 0))
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
	if (ft_isdigit(*start) == 1 || start == NULL)
	{
		err->get_start = 1;
		return (NULL);
	}
	if (*start == '{')
	{
		*in_braces = 1;
		start++;
	}
	return (start);
}

//A function that sets the result char * of the expanding the $ sign
static char	*ft_get_result(char *start, t_shell *shell, int in_braces, t_error *err)
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
		result = ft_strjoin(target, start + 1);
		free(target);
	}
	else
	{
		target = ft_calloc(ft_varlen(start, in_braces, err) + 1, sizeof(char));
		ft_strlcpy(target, start, ft_varlen(start, in_braces, err) + 1);
		env = getenv(target);
		result = ft_strjoin(env, &start[ft_varlen(start, in_braces, err)]);
		if (env)
			free(env);
		free(target);
	}
	return (result);
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

//A function that exapands the content of a dollar inside a string
int	ft_expand_dollar(char *dollar, t_shell *shell, t_error *err)
{
	char	*start;
	char	*result;
	char	*temp;
	int		in_braces;

	if (!dollar || !(*dollar))
		return (err->expand_dollar = 1);
	in_braces = 0;
	start = ft_get_start(dollar, &in_braces, err);
	if (!start)
		return (err->expand_dollar = 1);
	temp = ft_substr(dollar, 0, ft_strchr(dollar, '$') - dollar);
	result = ft_strjoin(temp , ft_get_result(start, shell, in_braces, err));
	free(temp);
	free(dollar);
	dollar = result;
	return (err->expand_dollar = 0);
}
