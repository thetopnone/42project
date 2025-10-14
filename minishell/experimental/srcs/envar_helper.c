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

#include "../../minishell.h"

//we will use the 3 argument form of int main(argc, argv, envp)
//Envp is a pointer to the environment variable array from the system
//We need to create our own copy of this array in the form of a linked list
//is_exported will always be set to 1 in our minishell because we will only
//be adding env variables using export. It will still be added as a flag to
//keep it accurate and close to the bash version of the export function
//
//This function will be checking if a string consists of valid character for
//a env variable name
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

//This function will create a new envar node with the arguments given
//and return a pointer to that node
t_envar	*ft_new_envar(char *key, char *value, int is_exported, t_error *err)
{
	t_envar	*res;

	if (!key || ft_valid_env(key, err) == 1)
	{
		err->new_envar = 1;
		return (NULL);
	}
	res = ft_calloc(1, sizeof(t_envar));
	res->key = ft_strdup(key);
	res->value = ft_strdup(value);
	res->is_exported = is_exported;
	err->new_envar = 0;
	return (*res)
}

//We need a function that sets the exportable env vars array

//We need a function that set the env array with all available envs
