/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:52:18 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/16 13:12:30 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	*start_of_str;

	start_of_str = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 'a' - 'A';
		str++;
	}
	str = start_of_str;
	return (str);
}

/*int	main(void)
{
	char	str[] = "14sdaaeDDSdfDD92@";

	printf("%s", ft_strlowcase(str));
	return (0);
}*/
