/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:35:47 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/10 12:35:49 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_num_dup(char **arguments, t_error *error)
{
	int		i;
	int		j;

	if (!arguments)
		return (1);
	j = 0;
	while (arguments[j])
	{
		i = j + 1;
		while (arguments[i])
		{
			if (ft_atol(arguments[i], error) == ft_atol(arguments[j], error))
				return (error->duplicate_nums = 1);
			i++;
		}
		j++;
	}
	return (error->duplicate_nums = 0);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	char	**arguments;
	int		chunks;
	t_error	error;

	if (argc < 2)
		return (1);
	ft_bzero(&error, sizeof(t_error));
	arguments = ft_get_arguments(argc, argv);
	ft_check_input(arguments, &error);
	if (ft_check_error(&error) == 1)
	{
		ft_free_args(arguments);
		ft_printf("Error\n");
		return (-1);
	}
	ft_initialize_stacks(&a, &b, arguments, &error);
	chunks = ft_set_chunk_amount(arguments);
	ft_free_args(arguments);
	ft_push_swap(&a, &b, chunks);
	ft_stack_clear(&a);
	free(b);
	return (0);
}
