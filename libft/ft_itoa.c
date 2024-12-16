/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:06:27 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/17 01:00:04 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	ft_char_amount(int n)
{
	unsigned int	char_amount;
	unsigned int	abs_n;

	char_amount = 0;
	if (n < 0)
	{
		abs_n = -n;
		char_amount++;
	}
	else
		abs_n = n;
	while (abs_n > 9)
	{
		char_amount++;
		abs_n = abs_n / 10;
	}
	char_amount++;
	return (char_amount);
}

static unsigned int	ft_pow(int n, unsigned int power)
{
	unsigned int	result;

	result = 1;
	if (power > 0)
	{
		result *= n;
		ft_pow(n, power - 1);
	}
	return (result);
}

static unsigned int	ft_abs(int n)
{
	unsigned int	value;

	if (n < 0)
		value = -n;
	else
		value = n;
	return (value);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	abs_n;
	unsigned int	index;
	unsigned int	char_amount;

	char_amount = ft_char_amount(n);
	index = char_amount - 1;
	result = malloc((char_amount + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	abs_n = ft_abs(n);
	while (index >= 0)
	{
		result[index] = (abs_n % 10) + '0';
		abs_n / 10;
		index--;
	}
	result[char_amount] = '\0';
	return (result);
}
