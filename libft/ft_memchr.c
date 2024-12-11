/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:39:46 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/11 18:11:21 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*strrf;

	strrf = (unsigned char *)s;
	while (n > 0)
	{
		if (c == (unsigned char)*strrf)
			return ((void *)strrf);
		strrf++;
		n--;
	}
	return (NULL);
}
