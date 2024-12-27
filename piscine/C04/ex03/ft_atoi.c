/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:46:19 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/24 17:57:32 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	unsigned int	charnum;
	int				is_negative;

	is_negative = 1;
	charnum = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 12))
		str++;
	while ((*str == '+' || *str == '-') && *str)
	{
		if (*str == '-')
			is_negative = -is_negative;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		charnum = charnum * 10 + (*str - '0');
		str++;
	}
	return (is_negative * charnum);
}
/*
int main(void)
{
	printf("%d", ft_atoi("\f \n-++++--+9011"));
	return (0);
}*/
