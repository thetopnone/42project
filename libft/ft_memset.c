/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:24:19 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/06 19:39:34 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *buffer, int c, size_t n)
{
	unsigned char	*refer;
	unsigned char	i;

	refer = buffer;
	i = (unsigned char)c;
	while (n > 0)
	{
		*refer = i;
		refer++;
		n--;
	}
	return (buffer);
}
