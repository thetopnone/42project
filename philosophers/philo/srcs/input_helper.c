/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:36:59 by akonstan          #+#    #+#             */
/*   Updated: 2025/11/26 15:37:00 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//checks if a string consists only of numbers
static int	ft_isnumstr(char *s)
{
	if (!s)
		return (1);
	while (*s && *s >= '0' && *s <= '9')
		s++;
	if (*s)
		return (1);
	return (0);
}

static int	ft_atoi_mini(char *s)
{
	int	res;

	if (ft_isnumstr(s))
		return (-1);
	res = 0;
	while (*s)
	{
		res *= 10;
		res += *s - '0';
		s++;
	}
	return (res);
}

int	ft_check_input(int argc, char **argv)
{
	size_t	i;

	if (argc > 6 || argc < 5)
		return (1);
	i = 1;
	while (argv[i])
	{
		if (ft_isnumstr(argv[i]) || ft_atoi_mini(argv[i]) == -1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_get_input(char **argv, int *input)
{
	size_t	i;

	i = 0;
	while (argv[i + 1])
	{
		input[i] = ft_atoi_mini(argv[i + 1]);
		i++;
	}
	if (i == 4)
		input[i] = -1;
}
