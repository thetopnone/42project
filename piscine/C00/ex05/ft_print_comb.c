/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:34:03 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/09 12:26:33 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(char n1, char n2, char n3)
{
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, &n3, 1);
}

void	ft_print_comb(void)
{
	char	dig_1;
	char	dig_2;
	char	dig_3;

	dig_1 = '0';
	while (dig_1 <= '7')
	{
		dig_2 = dig_1 + 1;
		while (dig_2 <= '8')
		{
			dig_3 = dig_2 + 1;
			while (dig_3 <= '9')
			{
				ft_print_numbers(dig_1, dig_2, dig_3);
				if (dig_1 != '7')
				{
					write(1, ", ", 2);
				}
				dig_3++;
			}
			dig_2++;
		}
		dig_1++;
	}
}
