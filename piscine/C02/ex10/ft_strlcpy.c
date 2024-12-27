/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:53:19 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/16 18:55:50 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//This function should return the size of the dest buffer
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_size;

	src_size = 0;
	while (*src)
	{
		if (src_size < size - 1)
		{
			*dest = *src;
			dest++;
		}
		else
			*dest = '\0';
		src++;
		src_size++;
	}
	return (src_size);
}

/*int	main(void)
{
	char	src[26] = "Hello, bitch, this is war";
	char	dest[20];
	unsigned int result;

	result = ft_strlcpy(dest, src, 20);
	printf("source : %s\n", src);
	printf("destination : %s\n", dest);
	printf("size of src : %u\n", result);
}*/
