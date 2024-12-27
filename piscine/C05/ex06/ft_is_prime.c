/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:14:05 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/23 13:57:12 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_is_divider(int nb, int divider)
{
	int	boolean;

	boolean = 1;
	if (nb % divider == 0 && nb / divider != 0)
		boolean = 0;
	return (boolean);
}

int	ft_is_prime(int nb)
{
	int	result;
	int	divider;

	result = 1;
	divider = nb - 1;
	if (nb <= 1)
		return (0);
	while (divider > 1)
	{
		if (ft_is_divider(nb, divider) == 0)
			return (0);
		else
			divider--;
	}
	return (result);
}
/*
int main(void)
{
	printf("%d", ft_is_prime(4));
	return (0);
}*/
