/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:22:42 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/23 18:34:50 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	**refer_to_argv;
	char	*current_arg;
	int		argsize;

	argsize = argc - 1;
	while (argsize > 0)
	{
		refer_to_argv = argv + argsize;
		current_arg = *refer_to_argv;
		while (*current_arg)
		{
			write(1, current_arg, 1);
			current_arg++;
		}
		write(1, "\n", 1);
		argsize--;
	}
}
