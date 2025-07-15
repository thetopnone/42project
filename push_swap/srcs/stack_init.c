/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:35:36 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/10 12:35:39 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_initialize_stacks(t_node **a, t_node **b, char **args, t_error *error)
{
	int		j;
	long	count;

	j = 0;
	count = ft_get_arg_count(args);
	*a = NULL;
	*b = NULL;
	while (j < count)
	{
		ft_nodeadd_back(a, ft_nodenew(ft_atol(args[j], error), j));
		j++;
	}
	return (0);
}

void	ft_check_input(char **arguments, t_error *error)
{
	int		i;
	long	num;
	int		int_max;
	int		int_min;

	i = 0;
	num = 0;
	int_max = ((unsigned int)(-1)) / 2;
	int_min = -int_max - 1;
	if (!arguments)
	{
		error->null_args = 1;
		return ;
	}
	while (arguments[i])
	{
		num = ft_atol(arguments[i++], error);
		if (num > int_max || num < int_min)
			error->out_of_bounds = 1;
	}
	if (ft_get_arg_count(arguments) == 1)
		return ;
	ft_check_num_dup(arguments, error);
}

char	**ft_get_arguments(int argc, char **argv)
{
	char	**arguments;
	int		counter;

	counter = 0;
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
	{
		arguments = ft_calloc(argc, sizeof(char *));
		if (!arguments)
			return (NULL);
		while (argv[counter + 1])
		{
			arguments[counter] = ft_strdup(argv[counter + 1]);
			counter++;
		}
		arguments[counter] = NULL;
	}
	return (arguments);
}

int	ft_check_error(t_error *error)
{
	int	result;

	result = 0;
	if (error->not_numbers == 1)
		result = 1;
	else if (error->null_args == 1)
		result = 1;
	else if (error->out_of_bounds == 1)
		result = 1;
	else if (error->duplicate_nums == 1)
		result = 1;
	return (result);
}

long	ft_get_arg_count(char **argv)
{
	long	result;

	result = 0;
	while (argv[result])
		result++;
	return (result);
}
