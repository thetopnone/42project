/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:27:58 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/13 18:36:49 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	char			*ref;
	unsigned int	value;
	int				sign;

	ref = (char *)nptr;
	value = 0;
	sign = 1;
	while (ft_isspace((int)*ref) == 0)
		ref++;
	if (*ref == '-')
	{
		sign *= -1;
		ref++;
	}
	if (*ref == '+')
		ref++;
	while (ft_isdigit(*ref) == 1)
	{
		value = value * 10 + (*ref - '0');
		ref++;
	}
	return (sign * value);
}
