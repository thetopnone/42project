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
	{
		err->envar_amount = 1;
		return (0);
	}
	res = 0;
	while (envc)
	{
		res++;
		envc = envc->next;
	}
	err->envar_amount = 0;
	return (res);
}

//A function that exctracts the "key" from the envar passed
//Checked with board. Should work as intended
char	*ft_get_envp_key(char *envp, t_error *err)
{
	char	*key;
	char	*ref;
	size_t	key_len;

	if (!envp)
	{
		err->get_envp_key = 1;
		return (NULL);
	}
	key_len = 0;
	ref = envp;
	while (*ref && *ref != '=')
		ref++;
	key_len = ref - envp; 
	key = ft_calloc(key_len + 1, sizeof(char));
	ft_strlcpy(key, envp, key_len + 1);
	err->get_envp_key = 0;
	return(key);
}

//A function that extracts the "value" of the envp passed to it
char	*ft_get_envp_value(char *envp, t_error *err)
{
	char	*value;
	char	*ref;
	size_t	value_len;

	if (!envp)
	{
		err->get_envp_value = 1;
		return (NULL);
	}
	value = NULL;
	ref = envp;
	value_len = 0;
	while (*ref && *ref != '=')
		ref++;
	ref++;
	value_len = ft_strlen(ref);
	value = ft_calloc(value_len + 1, sizeof(char));
	ft_strlcpy(value, ref, value_len + 1);
	err->get_envp_value = 0;
	return (ref);
}
