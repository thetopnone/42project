/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:49:49 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/16 17:06:08 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printhexval(char *c)
{
	int		decimal_val;
	int		div;
	int		mod;
	char	prt_div;
	char	prt_mod;

	decimal_val = *c;
	div = decimal_val / 16;
	mod = decimal_val % 16;
	if (mod > 9)
		prt_mod = 'a' + (mod - 10);
	else
		prt_mod = mod + '0';
	if (div > 9)
		prt_div = 'a' + (div - 10);
	else
		prt_div = div + '0';
	write(1, "\\", 1);
	write(1, &prt_div, 1);
	write(1, &prt_mod, 1);
}

int	ft_nonprint(char *str)
{
	int	nonprint;

	if (*str < 32 || *str > 126)
		nonprint = 1;
	else
		nonprint = 0;
	return (nonprint);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (ft_nonprint(str) == 0)
			write(1, str, 1);
		else
			ft_printhexval(str);
		str++;
	}
}

/*int main(void)
{
	char	str[] = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(str);
	return (0);
}*/
