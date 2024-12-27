/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:53:39 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/18 11:51:17 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_endofstr(char *str)
{
	while (*str)
		str++;
	return (str);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*start_of_dest;

	start_of_dest = dest;
	dest = ft_endofstr(dest);
	while (nb > 0 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	dest = start_of_dest;
	return (dest);
}
/*int	main(void)
{
	char dest[40] = "Mac 'n";
	char src[19] = " Cheese from Zabka";
	char *print;

	print = ft_strncat(dest, src ,sizeof(src));
	printf("\n%s", print);
	return (0);
}*/
