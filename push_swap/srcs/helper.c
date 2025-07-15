/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:34:08 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/11 11:34:09 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (0);
	return (1);
}

static int	ft_set_sign(char **ref)
{
	int	sign;

	sign = 1;
	if (**ref == '-' || **ref == '+')
	{
		if (**ref == '-')
			sign *= -1;
		(*ref)++;
	}
	return (sign);
}

//Converts a char to long and sets error if its is of undesired type
long	ft_atol(const char *nptr, t_error *error)
{
	char	*ref;
	long	value;
	int		sign;

	ref = (char *)nptr;
	value = 0;
	while (ft_isspace((int)*ref) == 0)
		ref++;
	sign = ft_set_sign(&ref);
	if (!*ref)
		return (error->not_numbers = 1);
	while (*ref)
	{
		if (ft_isdigit(*ref) == 1)
			value = value * 10 + (*ref - '0');
		if (*ref && ft_isdigit(*ref) == 0)
			return (error->not_numbers = 1);
		ref++;
	}
	return (sign * value);
}

//Calculates the signed numerical distance between 2 numbers
long long	ft_dist(long value1, long value2)
{
	return (value1 - value2);
}

//Free the arguments char**
void	ft_free_args(char **arguments)
{
	int	counter;

	counter = ft_get_arg_count(arguments);
	while (counter > 0)
	{
		free(arguments[--counter]);
	}
	free (arguments);
}
