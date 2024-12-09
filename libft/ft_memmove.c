/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:33:02 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/08 22:11:42 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_overlapcheck(unsigned char *dest, unsigned char *src, size_t bytes)
{
	if (src < dest && dest < src + bytes)
	{
		return (1);
	}
	else
		return (0);
}

void	ft_writefw(unsigned char *dest, unsigned char *src, size_t bytes)
{
	while (bytes > 0)
	{
		*dest = *src;
		dest++;
		src++;
		bytes--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destrf;
	unsigned char	*srcrf;

	destrf = dest;
	srcrf = (unsigned char *)src;
	if (ft_overlapcheck(destrf, srcrf, n) == 1)
	{
		destrf += n - 1;
		srcrf += n - 1;
		while (n > 0)
		{
			*destrf = *srcrf;
			destrf--;
			srcrf--;
			n--;
		}
	}
	else
		ft_writefw(destrf, srcrf, n);
	return (dest);
}
