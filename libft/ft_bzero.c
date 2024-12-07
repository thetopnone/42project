/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:41:10 by akonstan          #+#    #+#             */
/*   Updated: 2024/12/07 18:05:13 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *buffer, size_t n)
{
	unsigned char	*refer;

	refer = (unsigned char *)buffer;
	while (n > 0)
	{
		*refer = 0;
		refer++;
		n--;
	}
}
