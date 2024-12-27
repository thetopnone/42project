/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:53:13 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/22 12:25:40 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*start_of_str;
	char	*start_of_to_find;

	start_of_str = str;
	start_of_to_find = to_find;
	while (*str && *to_find)
	{
		to_find = start_of_to_find;
		if (*str == *to_find)
		{
			start_of_str = str;
			while (*str == *to_find && *to_find && *str)
			{
				str++;
				to_find++;
			}
		}
		if (*str == '\0')
			break ;
		str++;
	}
	if ((to_find == start_of_to_find && *to_find) || (!(*str) && *to_find))
		return (NULL);
	str = start_of_str;
	return (str);
}
/*int	main(void)
{
	char	str[] = "I am rally hoping to find the mistake in here";
	char	to_find[] = "re";

	//str = ft_strstr(str, to_find);
	printf("%s", ft_strstr(str, to_find));
	printf("\n%s", strstr(str, to_find));
	return (0);
}*/
