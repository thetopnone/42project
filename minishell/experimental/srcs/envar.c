/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:49:54 by akonstan          #+#    #+#             */
/*   Updated: 2025/09/26 18:49:55 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//We need a function that returns the envp array with all available envar
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
	while(envc)
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

//This function takes the third argument of the main function and turns it
//into an envc chain
t_envar	*ft_set_envc(char **envp, t_error *err)
{
	t_envar	*envc;
	char	*key;
	char	*value;
	int		i;

	if (!envp)
	{
		err->set_envc = 1;
		return (NULL);
	}
	i = 0;
	envc = NULL;
	key = NULL;
	value = NULL;
	while (envp[i])
	{
		key = ft_get_envp_key(envp[i], err);
		value = ft_get_envp_value(envp[i], err);
		ft_add_envar(&envc, ft_new_envar(key, value, 1, err), err);
		free(key);
		free(value);
		i++;
	}
	err->set_envc = 0;
	return (envc);
}
