/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:26:15 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/21 11:38:06 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strsize(char *str)
{
	unsigned int	str_size;

	str_size = 0;
	while (*str)
	{
		str++;
		str_size++;
	}
	return (str_size);
}

//Function should return the length of src
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_size;
	unsigned int	dest_size;

	dest_size = ft_strsize(dest);
	src_size = ft_strsize(src);
	if (size <= dest_size)
		return (size + src_size);
	size -= dest_size;
	dest += dest_size;
	while (*src != '\0' && size > 1)
	{
		*dest = *src;
		dest++;
		size--;
		src++;
	}
	*dest = '\0';
	return (dest_size + src_size);
}
/*
int	main(void)
{
	char	dest[25] = "1235 43based";
	char	src[15] = "born to code";
	unsigned int  a = ft_strlcat(dest, src, 8);

	printf("%s\n%d", dest, a);
	return (0);
}*/
