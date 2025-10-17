/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:49:31 by akonstan          #+#    #+#             */
/*   Updated: 2025/09/26 18:49:36 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//we will use the 3 argument form of int main(argc, argv, envc)
//envc is a pointer to the environment variable array from the system
//We need to create our own copy of this array in the form of a linked list
//is_exported will always be set to 1 in our minishell because we will only
//be adding env variables using export. It will still be added as a flag to
//keep it accurate and close to the bash version of the export function
//
//This function will be checking if a string consists of valid characters for
//an env variable name
int		ft_valid_env(char *key, t_error *err)
{
	if (!key)
		return (err->valid_env = 1);
	while (*key && ft_isenvchar(*key))
		key++;
	if (*key)
		return (err->valid_env = 1);
	return (err->valid_env = 0);
}

//A function that returns the amount of environment variables in the t_envar
//chain
size_t	ft_envar_amount(t_envar *envc, t_error *err)
{
	size_t	res;

	if (!envc)
		return (0);
	res = 0;
	while (*envc)
	{
		res++;
		envc = envc->next;
	}
	return (res);
}

//We need a function that set the envp array with all available envar
char	**ft_set_envp(t_envar *envc, t_error *err)
{
	char	**envp;
	char	*key;
	char	*value;

	if (!envc)
	{
		err->set_envp = 1;
		return (NULL);
	}
	envp = ft_calloc(ft_envar_amount(envc, err), sizeof(char *));
	key = NULL;
	value = NULL;
	while(*envc)
	{
		key = ft_strjoin(ft_strdup(envc->key), "=");
		value = ft_strdup(envc->value);
		*envp = ft_strjoin(key, value);
		free(key);
		free(value);
		envp++;
		envc = envc->next;
	}
	*envp = NULL;
	err->set_envp = 0;
	return (envp);
}
