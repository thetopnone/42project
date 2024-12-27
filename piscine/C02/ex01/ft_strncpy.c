/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:34:50 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/16 18:45:24 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*start_of_str;

	start_of_str = dest;
	while (n > 0)
	{
		if (*src != '\0')
			*dest = *src ;
		else
			*dest = '\0';
		src++;
		dest++;
		n--;
	}
	dest = start_of_str;
	return (dest);
}

/*int	main(void)
{
	char	src[6] = "Hello";
	char	dest[8];

	ft_strncpy(dest, src, 2);
	printf("%s\n%lu", dest, sizeof(dest));
	return (0);
}*/
