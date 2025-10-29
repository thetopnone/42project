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
//This function returns a pionter to the last node in a t_envar list
t_envar	*ft_get_last_envar(t_envar *envc, t_error *err)
{
	if (!envc)
	{
		err->get_last_envar = 1;
		return (NULL);
	}
	while (envc->next)
		envc++;
	err->get_last_envar = 0;
	return (envc);
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
	return (res);
}

//We need a function that sets the exportable env vars array
int	ft_add_envar(t_envar **envc, t_envar *var, t_error *err)
{
	if (!envc || !var)
		return (err->add_envar = 1);
	if (!*envc)
		*envc = var;
	else
		ft_get_last_envar(*envc, err)->next = var;
	return (err->add_envar = 0);
}

//A function to delete the stated var from envar
int	ft_del_envar(t_envar **envc, t_envar *var, t_error *err)
{
	t_envar	*prev;
	t_envar	*cur;

	if (!envc || !var)
		return (err->del_envar = 1);
	cur = *envc;
	prev = NULL;
	while (cur && ft_strncmp(cur->key, var->key, ft_strlen(cur->key) + 1) != 0)
	{
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
		return (err->del_envar = 1);
	if (prev)
		prev->next = cur->next;
	else
		*envc = (*envc)->next;
	free(cur->key);
	free(cur->value);
	free(cur);
	return (err->del_envar = 0);
}

//A function that returns a pointer to an env variable that has the
//stated key
t_envar	*ft_get_envar(t_envar *envc, char *key, t_error *err)
{
	if (!envc || !key)
	{
		err->get_envar = 1;
		return (NULL);
	}
	while (!ft_strncmp(envc->key, key, ft_strlen(key)))
		envc = envc->next;
	err->get_envar = 0;
	if (!envc)
		return (NULL);
	return (envc);
}
