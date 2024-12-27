/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:59:47 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/23 18:48:42 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*current_arg;

	current_arg = *argv;
	if (argc == 0)
		return (1);
	while (*current_arg)
	{
		write(1, current_arg, 1);
		current_arg++;
	}
	write(1, "\n", 1);
	return (0);
}
