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

//Converts a char to long and sets error if its is of undesired type
long	ft_atol(const char *nptr, t_error *error)
{
	char	*ref;
	long	value;
	int		sign;

	ref = (char *)nptr;
	value = 0;
	sign = 1;
	while (ft_isspace((int)*ref) == 0)
		ref++;
	if (*ref == '-' || *ref == '+')
	{
		if (*ref == '-')
			sign *= -1;
		ref++;
	}
	while (ft_isdigit(*ref) == 1)
	{
		value = value * 10 + (*ref - '0');
		ref++;
		if (*ref && ft_isdigit(*ref) == 0)
			return (error->invalid_input = 1);
	}
	return (sign * value);
}

//Calculates the numerical distance between 2 numbers
long long	ft_abs_dist(long value1, long value2)
{
	long long	result;

	result = value1 - value2;
	if (result < 0)
		return (result *= -1);
	return (result);
}
