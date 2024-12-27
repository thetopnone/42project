/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:23:18 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/22 14:13:29 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_basesize(char *base)
{
	char	*refer;
	int		size;

	refer = base;
	size = 0;
	while (*refer)
	{
		size++;
		refer++;
	}
	return (size);
}

int	ft_base_check(char *base)
{
	char	*refer;
	char	*comp;

	refer = base;
	if (ft_basesize(refer) < 2)
		return (1);
	while (*refer)
	{
		if (*refer == '+' || *refer == '-')
			return (1);
		comp = refer + 1;
		while (*comp)
		{
			if (*comp == *refer)
				return (1);
			comp++;
		}
		refer++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char			numchar;
	unsigned int	nb;

	if (ft_base_check(base) == 1)
		return ;
	if (nbr < 0)
	{
		nb = -nbr;
		ft_putchar('-');
	}
	else
		nb = nbr;
	if (nb > ft_basesize(base) - 1)
	{
		numchar = *(base + (nb % ft_basesize(base)));
		ft_putnbr_base(nb / ft_basesize(base), base);
		ft_putchar(numchar);
	}
	else
	{
		numchar = *(base + nb);
		ft_putchar(numchar);
	}
}
