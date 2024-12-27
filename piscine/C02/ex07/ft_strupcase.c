/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:49:28 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/16 12:54:21 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*start_of_str;

	start_of_str = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	str = start_of_str;
	return (str);
}

/*int	main(void)
{
	char str[] = "AsdFkgJGjkGk";

	printf("%s", ft_strupcase(str));
	return (0);
}*/
