/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:30:23 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/23 14:43:03 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	unsigned int	result;

	result = 1;
	if (nb < 0)
		return (0);
	if (nb > 0)
		result = nb * ft_recursive_factorial(nb - 1);
	return (result);
}
/*
int main(void)
{
	printf("%d", ft_recursive_factorial(0));
	return (0);
}*/
