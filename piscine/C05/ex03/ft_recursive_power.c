/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:24:58 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/23 14:40:51 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (result);
	if (power > 0)
		result *= nb * ft_recursive_power(nb, power - 1);
	return (result);
}
/*
int	main(void)
{
	printf("%d", ft_recursive_power(-10, 4));

	return (0);
}*/
