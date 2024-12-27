/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:12:55 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/15 17:18:18 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	is_lowercase;

	is_lowercase = 1;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			is_lowercase = 1;
		else
			return (0);
		str++;
	}
	return (is_lowercase);
}

/*int	main(void)
{
	char str[] = "asdekGf";

	printf("%d", ft_str_is_lowercase(str));

	return (0);
}*/
