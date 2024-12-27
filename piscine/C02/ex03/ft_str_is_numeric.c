/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:28:59 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/15 17:09:10 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	is_number;

	is_number = 1;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			is_number = 1;
		}
		else
			return (0);
		str++;
	}
	return (is_number);
}

/*int	main(void)
{
	char str[] = "";

	printf("%d", ft_str_is_numeric(str));
	return (0);
}*/
