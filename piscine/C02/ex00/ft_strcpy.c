/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:26:00 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/16 18:40:24 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*start_to_str;

	start_to_str = dest;

	if (*src == '\0')
		*dest = *src;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	dest = start_to_str;
	return (dest);
}

/*int	main(void)
{
	char	str1[20] = "C programming";
	char	str2[20];

	ft_strcpy(str2, str1);
	printf("%s",str2);
}*/
