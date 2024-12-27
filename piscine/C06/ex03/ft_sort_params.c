/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:35:36 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/24 14:20:21 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap_args(char **arg1, char **arg2)
{
	char	*temp;

	temp = *arg1;
	*arg1 = *arg2;
	*arg2 = temp;
}

int	ft_strcmp(char *str1, char *str2)
{
	int	diff;

	while (*str1 && *str2)
	{
		diff = *str1 - *str2;
		if (*str1 != *str2)
			return (diff);
		str1++;
		str2++;
	}
	diff = *str1 - *str2;
	return (diff);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_printargs(int argc, char **ptr)
{
	int	counter;

	counter = 0;
	while (counter < argc - 1)
	{
		ft_putstr(*(ptr + counter));
		counter++;
	}
}

int	main(int argc, char *argv[])
{
	char	**refer_to_argv;
	char	**comparator;
	int		argsize;
	int		swap;

	argsize = argc - 1;
	refer_to_argv = argv + 1;
	while (argsize > 0)
	{
		swap = 0;
		comparator = refer_to_argv;
		while (comparator < refer_to_argv + argsize - 1)
		{
			if (ft_strcmp(*comparator, *(comparator + 1)) > 0)
			{
				ft_swap_args(comparator, comparator + 1);
				swap = 1;
			}
			comparator++;
		}
		if (swap == 0)
			break ;
		argsize--;
	}
	ft_printargs(argc, refer_to_argv);
}
