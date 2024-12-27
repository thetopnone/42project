/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:20:25 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/15 17:25:17 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	is_uppercase;

	is_uppercase = 1;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			is_uppercase = 1;
		else
			return (0);
		str++;
	}
	return (is_uppercase);
}

/*int	main(void)
{
	char	str[] = "ASDKJFAHLSKJg";

	printf("%d", ft_str_is_uppercase(str));
	return (0);
}*/
