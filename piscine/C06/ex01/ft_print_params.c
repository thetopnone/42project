/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:06:38 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/23 17:19:07 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	**refer_to_argv;
	char	*current_arg;

	if (argc == 1)
		return (0);
	refer_to_argv = argv + 1;
	while (*refer_to_argv)
	{
		current_arg = *refer_to_argv;
		while (*current_arg)
		{
			write(1, current_arg, 1);
			current_arg++;
		}
		write(1, "\n", 1);
		refer_to_argv++;
	}
	return (0);
}
