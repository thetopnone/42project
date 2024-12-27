/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:36:40 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/09 15:30:52 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_nums(char num1, char num2, char num3, char num4)
{
	write(1, &num1, 1);
	write(1, &num2, 1);
	write(1, " ", 1);
	write(1, &num3, 1);
	write(1, &num4, 1);
	if (! (num1 == '9' && num2 == '8' && num3 == '9' && num4 == '9'))
		write(1, ", ", 2);
}

int	nm(char num1, char num2)
{
	int		number;
	char	number1[2];

	number1[0] = num1;
	number1[1] = num2;
	number = 1 * (num2 - '0') + 10 * (num1 - '0');
	return (number);
}

int	ft_cond_check(int number1, int number2)
{
	if (number1 < number2)
		return (0);
	else
		return (1);
}

void	ft_print_comb2(void)
{
	char	n1[2];
	char	n2[2];

	n1[0] = '0';
	while (n1[0] <= '9')
	{
		n1[1] = '0';
		while (n1[1] <= '9')
		{
			n2[0] = '0';
			while (n2[0] <= '9')
			{
				n2[1] = '0';
				while (n2[1] <= '9')
				{
					if (ft_cond_check(nm(n1[0], n1[1]), nm(n2[0], n2[1])) == 0)
						ft_write_nums(n1[0], n1[1], n2[0], n2[1]);
					n2[1]++;
				}
				n2[0]++;
			}
			n1[1]++;
		}
		n1[0]++;
	}
}
