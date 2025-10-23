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

int	main(int argc, char *argv[], char **envp)
{
	t_token	*chain;
	t_pipe	*pipeline;
	t_error	*error;
	t_shell	*shell;

	if (argc == 2)
	{
		error = ft_calloc(1, sizeof(t_error));
		shell = ft_calloc(1, sizeof(t_shell));
		shell->envc = ft_set_envc(envp, error);
		shell->envp = ft_set_envp(shell->envc, error);
		chain = lexer(argv[1], error);
		pipeline = ft_parser(&chain, error);
		ft_expander(pipeline, shell, error);
		print_pipeline(pipeline);
		ft_del_pipeline(&pipeline, error);
		free(error);
		free(shell);
	}
	return (0);
}
