/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:27:08 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/09 17:42:59 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	digit_amount(int number)
{
	int	dig_amount;

	dig_amount = 0;
	if (number == 0)
		dig_amount++;
	else
	{
		while (number != 0)
		{
			number = (number - (number % 10)) / 10;
			dig_amount++;
		}
	}
	return (dig_amount);
}

int	m_val(int cur_dig, int number)
{
	int	mod_val;
	int	size;

	mod_val = 1;
	size = digit_amount(number);
	while (cur_dig > 1)
	{
		mod_val *= 10;
		cur_dig--;
	}
	return (mod_val);
}

int	ft_is_negative(int number)
{
	if (number < 0)
		return (0);
	else
		return (1);
}

void	ft_putnbr(int number)
{
	int		size;
	int		dig_val;
	int		cur_dig;
	char	num;
	int		mv;

	size = digit_amount(number);
	cur_dig = size;
	if (ft_is_negative(number) == 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	while (cur_dig > 0)
	{
		mv = m_val(cur_dig, number);
		dig_val = (number - (number % mv)) / mv;
		num = dig_val + '0';
		write(1, &num, 1);
		number = number - (dig_val * mv);
		cur_dig--;
	}
}
