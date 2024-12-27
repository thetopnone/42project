/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:14:47 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/16 18:53:28 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_numchar(char *str)
{
	int	boolean;

	if (*str >= 'a' && *str <= 'z')
		boolean = 0;
	else if (*str >= 'A' && *str <= 'Z')
		boolean = 1;
	else if (*str >= '0' && *str <= '9')
		boolean = 2;
	else
		boolean = 3;
	return (boolean);
}

char	*ft_strcapitalize(char *str)
{
	char	*start_of_str;
	int		capitalize;

	start_of_str = str;
	capitalize = 0;
	if (ft_numchar(str) == 1)
	{
		capitalize = 1;
		str++;
	}
	while (*str)
	{
		if (ft_numchar(str) == 2)
			capitalize = 1;
		else if (ft_numchar(str) == 3)
			capitalize = 0;
		else if (ft_numchar(str) == 0 && capitalize == 0)
		{
			*str -= 'a' - 'A';
			capitalize = 1;
		}
		else if (ft_numchar(str) == 1 && capitalize = 1)
			*str += 'a' - 'A';
		str++;
	}
	str = start_of_str;
	return (str);
}

/*int	main(void)
{
	char	str[] = "42mots quarante-deux; cinquante+et+un";

	printf("%s", ft_strcapitalize(str));
	return (0);
}*/
