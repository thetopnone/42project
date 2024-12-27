/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:52:27 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/22 14:15:41 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	char			numchar;
	unsigned int	number;

	numchar = '0';
	if (nb < 0)
	{
		write(1, "-", 1);
		number = -nb;
	}
	else
		number = nb;
	if (number > 9)
	{
		numchar = number % 10 + 48;
		ft_putnbr(number / 10);
		write(1, &numchar, 1);
	}
	else
	{
		numchar = number + '0';
		write(1, &numchar, 1);
	}
}
/*
int	main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}*/
