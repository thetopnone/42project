/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:47:46 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/23 13:10:44 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (result);
	if (power > 0)
		result *= nb * ft_power(nb, power - 1);
	return (result);
}

int	ft_sqrt(int nb)
{
	int	result;
	int	counter;

	result = 0;
	counter = 0;
	while (nb >= ft_power(counter, 2))
	{
		if (nb == ft_power(counter, 2))
			return (result);
		result++;
		counter++;
	}
	return (0);
}
/*
int main(void)
{
	printf("%d", ft_sqrt(-10));
	//printf("%d", ft_power(1, 2));
	return (0);
}*/
