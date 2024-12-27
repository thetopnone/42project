/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:27:55 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/15 17:34:08 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	is_printable;

	is_printable = 1;
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			is_printable = 1;
		else
			return (0);
		str++;
	}
	return (is_printable);
}

/*int	main(void)
{
	char str[] = "  \"\\asdfgj287574y&$#*75149*&(**";

	printf("%d", ft_str_is_printable(str));
	return (0);
}*/
