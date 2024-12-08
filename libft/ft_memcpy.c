/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:08:07 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/07 18:16:59 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destrf;
	unsigned char	*srcrf;

	destrf = (unsigned char *)dest;
	srcrf = (const unsigned char *)src;
	while (n > 0)
	{
		*destrf = *srcrf;
		srcrf++;
		destrf++;
		n--;
	}
	return (dest);
}
