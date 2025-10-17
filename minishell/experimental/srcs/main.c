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

int	main(int argc, char *argv[])
{
	t_token	*chain;
	t_pipe	*pipeline;
	t_error	*error;

	if (argc == 2)
	{
		error = ft_calloc(1, sizeof(t_error));
		chain = lexer(argv[1]);
		pipeline = ft_parser(&chain, error);
	}
	return (0);
}
