/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:30:49 by akonstan          #+#    #+#             */
/*   Updated: 2024/10/21 11:25:41 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*start_of_str;

	start_of_str = dest;
	while (*dest != '\0')
		dest++;
	while (*src > '\0')
	{
		*dest = *src;
		dest++;
		src++;
		if (! (*src))
			*dest = '\0';
	}
	dest = start_of_str;
	return (dest);
}
